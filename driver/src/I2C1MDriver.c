#include "driver/inc/I2C1MDriver.h"

cy_stc_scb_i2c_context_t I2C1M_MCU_context;
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
uint8_t I2C1MDriver_Register_Event_Callback(cy_cb_scb_i2c_handle_events_t pCallback)
{
	uint8_t u8Result;
	if ((NULL != pCallback))
	{
		Cy_SCB_I2C_RegisterEventCallback (I2C1M_MCU_HW, pCallback, &I2C1M_MCU_context);
		u8Result = TRUE;
	}
	else
	{
		u8Result = FALSE;
	}
	return u8Result;
}

static void I2C1MDriver_Interrupt(void)
{
    Cy_SCB_I2C_Interrupt(I2C1M_MCU_HW, &I2C1M_MCU_context);
}

bool I2C1MDriver_Initialize(void)
{
    bool bresult = true;
    
    cy_en_scb_i2c_status_t initStatus;
    cy_en_sysint_status_t sysStatus;
    cy_stc_sysint_t CYBSP_I2C_SCB_IRQ_cfg =
    {
            /*.intrSrc =*/ I2C1M_MCU_IRQ,
            /*.intrPriority =*/ 3u
    };

    /*Initialize and enable the I2C in master mode*/
    initStatus = Cy_SCB_I2C_Init(I2C1M_MCU_HW, &I2C1M_MCU_config, &I2C1M_MCU_context);
    if(initStatus != CY_SCB_I2C_SUCCESS)
    {
        bresult = false;
    }

    /* Hook interrupt service routine */
    sysStatus = Cy_SysInt_Init(&CYBSP_I2C_SCB_IRQ_cfg, &I2C1MDriver_Interrupt);
    if(sysStatus != CY_SYSINT_SUCCESS)
    {
        bresult = false;
    }

    NVIC_EnableIRQ((IRQn_Type) CYBSP_I2C_SCB_IRQ_cfg.intrSrc);

    Cy_SCB_I2C_Enable(I2C1M_MCU_HW, &I2C1M_MCU_context);

    return bresult;
}

uint8_t I2C1MDriver_Read(uint16_t address, uint8_t* rdData, uint32_t rdLength)
{
    uint8_t status = ERROR_FAIL;
    cy_en_scb_i2c_status_t errorStatus;
    uint32_t masterStatus;
    /* Timeout 1 sec (one unit is us) */
    uint32_t timeout = 1000000UL;

    /* Setup transfer specific parameters */
    masterTransferCfg.slaveAddress = (uint8_t)(address & 0x00FF);
    masterTransferCfg.buffer     = rdData;
    masterTransferCfg.bufferSize = rdLength;

    /* Initiate read transaction */
    errorStatus = Cy_SCB_I2C_MasterRead(I2C1M_MCU_HW, &masterTransferCfg, &I2C1M_MCU_context);
    if(errorStatus == CY_SCB_I2C_SUCCESS)
    {
        /* Wait until master complete read transfer or time out has occurred */
        do
        {
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(I2C1M_MCU_HW, &I2C1M_MCU_context);
            Cy_SysLib_DelayUs(CY_SCB_WAIT_1_UNIT);
            timeout--;

        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeout > 0));

        if (timeout <= 0)
        {
            status = ERROR_TIMEOUT;
            /* Timeout recovery */
            Cy_SCB_I2C_Disable(I2C1M_MCU_HW, &I2C1M_MCU_context);
            Cy_SCB_I2C_Enable(I2C1M_MCU_HW, &I2C1M_MCU_context);
        }
        else
        {
            /* Check transfer status */
            if (0u == (MASTER_ERROR_MASK & masterStatus))
            {
                status = ERROR_NONE;
                /* Check packet structure and status */
            }else{
                status = ERROR_FAIL;
            }
        }
    }
    return (status);
}

uint8_t I2C1MDriver_Write(uint16_t address, uint8_t* wrData, uint32_t wrLength)
{
    uint8_t status = ERROR_FAIL;
    cy_en_scb_i2c_status_t  errorStatus;
    uint32_t masterStatus;
    /* Timeout 1 sec (one unit is us) */
    uint32_t timeout = 10000UL;

    /* Setup transfer specific parameters */
    masterTransferCfg.slaveAddress = (uint8_t)(address & 0x00FF);
    masterTransferCfg.buffer     = wrData;
    masterTransferCfg.bufferSize = wrLength;

    /* Initiate write transaction */
    errorStatus = Cy_SCB_I2C_MasterWrite(I2C1M_MCU_HW, &masterTransferCfg, &I2C1M_MCU_context);
    if(errorStatus == CY_SCB_I2C_SUCCESS)
    {
        /* Wait until master complete read transfer or time out has occured */
        do
        {
            masterStatus  = Cy_SCB_I2C_MasterGetStatus(I2C1M_MCU_HW, &I2C1M_MCU_context);
            Cy_SysLib_DelayUs(CY_SCB_WAIT_1_UNIT);
            timeout--;

        } while ((0UL != (masterStatus & CY_SCB_I2C_MASTER_BUSY)) && (timeout > 0));

        if (timeout <= 0)
        {
            status = ERROR_TIMEOUT;
            /* Timeout recovery */
            Cy_SCB_I2C_Disable(I2C1M_MCU_HW, &I2C1M_MCU_context);
            Cy_SCB_I2C_Enable(I2C1M_MCU_HW, &I2C1M_MCU_context);
        }
        else
        {
            if ((0u == (MASTER_ERROR_MASK & masterStatus)) &&
                (wrLength == Cy_SCB_I2C_MasterGetTransferCount(I2C1M_MCU_HW, &I2C1M_MCU_context)))
            {
                status = ERROR_NONE;
            }else{
                status = ERROR_FAIL;
            }
        }
    }
    return (status);
}
