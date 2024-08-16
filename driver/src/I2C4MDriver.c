#include "driver/inc/I2C4MDriver.h"

cy_stc_scb_i2c_context_t I2C4M_MCU_context;
cy_stc_scb_i2c_master_xfer_config_t masterTransferCfg =
{
    .slaveAddress = 0x00U,
    .buffer       = NULL,
    .bufferSize   = 0U,
    .xferPending  = false
};

/******************************************************************************
;       Function Name			:	uint8_t HAL_I2C_Slave_Register_Event_Callback(CySCB_Type const* pSCB,cy_cb_scb_i2c_handle_events_t 	pCallback)
;       Function Description	:	This state for error condition
;       Parameters				:	void
;       Return Values			:	void
;		Source ID				:
******************************************************************************/
uint8_t I2C4MDriver_Register_Event_Callback(cy_cb_scb_i2c_handle_events_t pCallback)
{
	uint8_t u8Result;
	if ((NULL != pCallback))
	{
		Cy_SCB_I2C_RegisterEventCallback (I2C4M_MCU_HW, pCallback, &I2C4M_MCU_context);
		u8Result = TRUE;
	}
	else
	{
		u8Result = FALSE;
	}
	return u8Result;
}

static void I2C4MDriver_Interrupt(void)
{
    Cy_SCB_I2C_Interrupt(I2C4M_MCU_HW, &I2C4M_MCU_context);
}

bool I2C4MDriver_Initialize(void)
{
    bool bresult = true;
    
    cy_en_scb_i2c_status_t initStatus;
    cy_en_sysint_status_t sysStatus;
    cy_stc_sysint_t CYBSP_I2C_SCB_IRQ_cfg =
    {
            /*.intrSrc =*/ I2C4M_MCU_IRQ,
            /*.intrPriority =*/ 3u
    };

    /*Initialize and enable the I2C in master mode*/
    initStatus = Cy_SCB_I2C_Init(I2C4M_MCU_HW, &I2C4M_MCU_config, &I2C4M_MCU_context);
    if(initStatus != CY_SCB_I2C_SUCCESS)
    {
        bresult = false;
    }

    /* Hook interrupt service routine */
    sysStatus = Cy_SysInt_Init(&CYBSP_I2C_SCB_IRQ_cfg, &I2C4MDriver_Interrupt);
    if(sysStatus != CY_SYSINT_SUCCESS)
    {
        bresult = false;
    }

    NVIC_EnableIRQ((IRQn_Type) CYBSP_I2C_SCB_IRQ_cfg.intrSrc);

    Cy_SCB_I2C_Enable(I2C4M_MCU_HW, &I2C4M_MCU_context);

    return bresult;
}

uint8_t I2C4MDriver_Read(uint16_t address, uint8_t* rdData, uint32_t rdLength)
{
    uint8_t status = ERROR_FAIL;
    cy_en_scb_i2c_status_t errorStatus;
    uint32_t masterStatus;
    /* Timeout 1 sec (one unit is us) */
    uint32_t timeout = 8000UL;

    /* Setup transfer specific parameters */
    masterTransferCfg.slaveAddress = (uint8_t)(address & 0x00FF);
    masterTransferCfg.buffer     = rdData;
    masterTransferCfg.bufferSize = rdLength;

    /* Initiate read transaction */
    errorStatus = Cy_SCB_I2C_MasterRead(I2C4M_MCU_HW, &masterTransferCfg, &I2C4M_MCU_context);
    if(errorStatus == CY_SCB_I2C_SUCCESS)
    {
        /* Wait until master complete read transfer or time out has occurred */
        do
        {
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(I2C4M_MCU_HW, &I2C4M_MCU_context);
            Cy_SysLib_DelayUs(CY_SCB_WAIT_1_UNIT);
            timeout--;

        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeout > 0));
        if (timeout <= 0)
        {
            status = ERROR_TIMEOUT;
            /* Timeout recovery */
            Cy_SCB_I2C_Disable(I2C4M_MCU_HW, &I2C4M_MCU_context);
            Cy_SCB_I2C_Enable(I2C4M_MCU_HW, &I2C4M_MCU_context);
        }
        else
        {
            /* Check transfer status */
            switch (masterStatus & MASTER_ERROR_MASK)
            {
            case 0:
                status = ERROR_NONE;
                break;
            case CY_SCB_I2C_MASTER_DATA_NAK:
                /* code */
                status = ERROR_NAK;
                break;
            
            case CY_SCB_I2C_MASTER_ADDR_NAK:
                /* code */
                status = ERROR_NAK;
                break;

            case CY_SCB_I2C_MASTER_ARB_LOST:
                /* code */
                status = ERROR_FAIL;
                break;

            case CY_SCB_I2C_MASTER_ABORT_START:
                /* code */
                status = ERROR_FAIL;
                break;

            case CY_SCB_I2C_MASTER_BUS_ERR:
                /* code */
                status = ERROR_FAIL;
                break;

            default:
                status = ERROR_FAIL;
                break;
            }
        }
    }
    return (status);
}

uint8_t I2C4MDriver_Write(uint16_t address, uint8_t* wrData, uint32_t wrLength)
{
    uint8_t status = ERROR_FAIL;
    cy_en_scb_i2c_status_t  errorStatus;
    uint32_t masterStatus;
    /* Timeout 1 sec (one unit is us) */
    uint32_t timeout = 8000UL;

    /* Setup transfer specific parameters */
    masterTransferCfg.slaveAddress = (uint8_t)(address & 0x00FF);
    masterTransferCfg.buffer     = wrData;
    masterTransferCfg.bufferSize = wrLength;

    /* Initiate write transaction */
    errorStatus = Cy_SCB_I2C_MasterWrite(I2C4M_MCU_HW, &masterTransferCfg, &I2C4M_MCU_context);
    if(errorStatus == CY_SCB_I2C_SUCCESS)
    {
        /* Wait until master complete read transfer or time out has occured */
        do
        {
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(I2C4M_MCU_HW, &I2C4M_MCU_context);
            Cy_SysLib_DelayUs(CY_SCB_WAIT_1_UNIT);
            timeout--;

        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeout > 0));

        if (timeout <= 0)
        {
            status = ERROR_TIMEOUT;
            /* Timeout recovery */
            Cy_SCB_I2C_Disable(I2C4M_MCU_HW, &I2C4M_MCU_context);
            Cy_SCB_I2C_Enable(I2C4M_MCU_HW, &I2C4M_MCU_context);
        }
        else
        {
            /* Check transfer status */
            switch (masterStatus & MASTER_ERROR_MASK)
            {
            case 0:
                status = ERROR_NONE;
                break;
            case CY_SCB_I2C_MASTER_DATA_NAK:
                /* code */
                status = ERROR_NAK;
                break;
            
            case CY_SCB_I2C_MASTER_ADDR_NAK:
                /* code */
                status = ERROR_NAK;
                break;

            case CY_SCB_I2C_MASTER_ARB_LOST:
                /* code */
                status = ERROR_FAIL;
                break;

            case CY_SCB_I2C_MASTER_ABORT_START:
                /* code */
                status = ERROR_FAIL;
                break;

            case CY_SCB_I2C_MASTER_BUS_ERR:
                /* code */
                status = ERROR_BUSNG;
                break;

            default:
                status = ERROR_FAIL;
                break;
            }
        }
    }
    return (status);
}

uint8_t I2C4MDriver_WriteRead(uint16_t address, uint8_t* wrData, uint32_t wrLength, uint8_t* rdData, uint32_t rdLength)
{
    cy_en_scb_i2c_status_t status;
    /* Timeout 8 msec (one unit is ms) */
    uint32_t timeoutMs = 8UL;
    /* Send Start condition, address and receive ACK/NACK response from slave */
	status = Cy_SCB_I2C_MasterSendStart(I2C4M_MCU_HW, address, CY_SCB_I2C_WRITE_XFER, timeoutMs, &I2C4M_MCU_context);
	if (CY_SCB_I2C_SUCCESS == status)
	{
        for (uint32_t i = 0 ; i < wrLength ; i ++)
		{
			  status = Cy_SCB_I2C_MasterWriteByte(I2C4M_MCU_HW, wrData[i], timeoutMs, &I2C4M_MCU_context);
			  if (status != CY_SCB_I2C_SUCCESS)
			  	  {break;}
			  else
				  {continue;}
		}
        if(status == CY_SCB_I2C_SUCCESS)
        {
            if(rdLength > 0U)
            {
                /*Send restart bit*/
                Cy_SCB_I2C_MasterSendReStart(I2C4M_MCU_HW,
                                            address,
                                            CY_SCB_I2C_READ_XFER,
                                            timeoutMs,
                                            &I2C4M_MCU_context);
                /*Read data & send NAK*/
                uint32_t cnt = 0UL;
                cy_en_scb_i2c_command_t cmd = CY_SCB_I2C_ACK;
                while ((status == CY_SCB_I2C_SUCCESS) && (cnt < rdLength))
                {
                    /* code */
                    if (cnt == (rdLength - 1UL))
                    {
                        /* The last byte must be NACKed */
                        cmd = CY_SCB_I2C_NAK;
                    }
                    /* Read byte and generate ACK / or prepare for NACK */
                    status = Cy_SCB_I2C_MasterReadByte(I2C4M_MCU_HW, cmd, &rdData[cnt], timeoutMs, &I2C4M_MCU_context);
                    ++cnt;
                }
            }else{
                /* Do nothing*/
            }

            /* Send Stop condition on the bus */
            /* Check status of transaction */
            if ((status == CY_SCB_I2C_SUCCESS)           ||
                (status == CY_SCB_I2C_MASTER_MANUAL_NAK) ||
                (status == CY_SCB_I2C_MASTER_MANUAL_ADDR_NAK))
            {
                /* Send Stop condition on the bus */
                status = Cy_SCB_I2C_MasterSendStop(I2C4M_MCU_HW, timeoutMs, &I2C4M_MCU_context);
            }
            else
            {
                /* Other statuses do not require any actions.
                * The received data should dropped.
                */
            }
        }
        else
        {
            /* do not requite any actions*/
        }
    }
    else
    {
        /* do not requite any actions*/
    }
    if(status == CY_SCB_I2C_MASTER_MANUAL_TIMEOUT){
        Cy_SCB_I2C_Disable(I2C4M_MCU_HW, &I2C4M_MCU_context);
        Cy_SCB_I2C_Enable(I2C4M_MCU_HW, &I2C4M_MCU_context);
    }
    return (status);
}