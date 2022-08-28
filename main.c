#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

cyhal_pwm_t pwm_obj;
int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init() ;
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    __enable_irq();

    cyhal_pwm_init(&pwm_obj, CYBSP_USER_LED, NULL);
    cyhal_pwm_start(&pwm_obj);
    int x=0;
    for (;;)
    {
    	cyhal_pwm_set_duty_cycle(&pwm_obj,x,5000);
    	x+=20;
    	cyhal_system_delay_ms(200);
    	if(x==120){
    		x=0;
    		cyhal_system_delay_ms(10);
    	}
    }
}

/* [] END OF FILE */
