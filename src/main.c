// Define base address for peripherals
#define PERIPH_BASE        (0x40000000UL)
// Offset for AHB1 peripheral bus
#define AHB1PERIPH_OFFSET  (0x00020000UL)
// Base address for AHB1 peripherals
#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1PERIPH_OFFSET)
// Offset for GPIOD
#define GPIOD_OFFSET       (0x0C00UL)
// Base address for GPIOD
#define GPIOD_BASE         (AHB1PERIPH_BASE + GPIOD_OFFSET)
// Offset for RCC
#define RCC_OFFSET         (0x3800UL)
// Base address for RCC
#define RCC_BASE           (AHB1PERIPH_BASE + RCC_OFFSET)
// Offset for AHB1EN register
#define AHB1EN_R_OFFSET    (0x30UL)
// Address of AHB1EN register
#define RCC_AHB1EN_R  (*(volatile unsigned int *)(RCC_BASE +  AHB1EN_R_OFFSET))
// Offset for mode register
#define MODE_R_OFFSET      (0x00UL)
// Address of GPIOD mode register
#define GPIOD_MODE_R  (*(volatile unsigned int *)(GPIOD_BASE + MODE_R_OFFSET))
// Offset for output data register
#define OD_R_OFFSET   (0x14UL)
// Address of GPIOD output data register
#define GPIOD_OD_R    (*(volatile unsigned int *)(GPIOD_BASE +  OD_R_OFFSET))
// Bit mask for enabling GPIOD (bit 0)
#define GPIODEN       (1U << 3)
// Bit mask for GPIOD pin 5
#define PIN12          (1U << 12)
// Alias for PIN5 representing LED pin
#define LED_PIN       PIN12

int main(void)
{
    RCC_AHB1EN_R |= GPIODEN;

    GPIOD_MODE_R |= (1U << 24);
    GPIOD_MODE_R &= ~(1U << 25);

    while(1)
    {
    	GPIOD_OD_R |= LED_PIN;
    }
}