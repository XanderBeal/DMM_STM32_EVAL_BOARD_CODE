
#include <SPI.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stm32f3xx_hal_rcc.h>
//I2C setup
#include <Wire.h>

//import files
#include "measure.hpp"
#include "cal.hpp"
#include "screenDisplay.hpp"


//variable declarations
double digitalValue = 0.00;// variable to store the value coming from the sensor



//One time executed code
void setup() {
  // HAL_RCC_DeInit();
  SystemClock_Config();
  // HAL_Init();
  // __HAL_RCC_GPIOC_CLK_ENABLE();
  // __HAL_RCC_GPIOB_CLK_ENABLE();
  // __HAL_RCC_GPIOA_CLK_ENABLE();
  Wire.setSDA(PB7);
  Wire.setSCL(PB6); 
  Wire.begin();
 //from display.cpp
  //analogReadResolution(16); //set bit count of ADC

  //displayTest();
  //Serial.begin(9600);  //serial setup for PC debugging

  /*
  display.display();
  delay(200); 
  display.clearDisplay();
  display.clearDisplay();
  
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);

*/
  pinMode(PA15, OUTPUT);
  
}

//Repeated code loop (allows the processor to continue opperating without needing manuealy reset)
void loop() {

  bootScreen();
  /* 
  General structure:
  - Ensure all gpio is set to low and nothing is configured on 
  - Display 
      - Startup screen
      - Display options (volts, amps, ohms, cal / rel)  
          - Buttons (single press for mode selection, another press for mode deactivation)
          - Ohms mode can have LED_Test blink when in continuity mode (< 10 Ohms resistance)
  - Configure ADC to mode
  - Take measurements
  - Take average according to mode
  - Store / display results
  */
  digitalWrite(PA15, HIGH);

  delay(30);

  digitalWrite(PA15, LOW);

  delay(30);


  //displayADC();
  
}


extern "C" void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}
  // PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  // PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  // if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  // {
  //   Error_Handler();
  // }
  // RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  // RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  // RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  // /** Initializes the RCC Oscillators according to the specified parameters
  // * in the RCC_OscInitTypeDef structure.
  // */
  // RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  // RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  // RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  // RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  // RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  // RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  // RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL8;
  // if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  // {
  //   Error_Handler();
  // }

  // /** Initializes the CPU, AHB and APB buses clocks
  // */
  // RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
  //                             |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  // RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  // RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  // RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  // RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  // if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  // {
  //   Error_Handler();
  // }
  // // PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  // // PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_SYSCLK;
  // // if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  // // {
  // //   Error_Handler();
  // // }

