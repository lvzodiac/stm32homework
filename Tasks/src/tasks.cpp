#include "tasks.h"
#include "main.h"

extern IWDG_HandleTypeDef hiwdg;
extern TIM_HandleTypeDef htim2;

volatile uint32_t tick = 0;

void Tasks_Init(void)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_TIM_Base_Start_IT(&htim2);
}

extern "C" void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        tick = tick + 1;
        //HAL_IWDG_Refresh(&hiwdg);
    }
}
