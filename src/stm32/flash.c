#include "includes.h"
#include "flash.h"

FLASH_EraseInitTypeDef eraseInitStruct;

void erase_flash(uint32_t beginAddress, uint32_t endAddress)
{
    uint32_t pageError = 0;
    HAL_FLASH_Unlock();

    eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    eraseInitStruct.PageAddress = beginAddress;
    eraseInitStruct.NbPages = (endAddress - beginAddress) / FLASH_PAGE_SIZE;

    if (HAL_FLASHEx_Erase(&eraseInitStruct, &pageError) != HAL_OK)
    {
        while (1)
        {
            //TODO add error handler
        }
    }
}

void erase_page(uint32_t pageAddress)
{
    WRITE_REG(FLASH->AR, pageAddress);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);
}

void erase_range(uint32_t beginAddress, uint32_t endAddress)
{
    if (beginAddress > endAddress)
    {
        while (1)
        {
            //TODO add error handler
        }
    }
    else if (beginAddress > RFBL_ADDRESS)
    {
        while (1)
        {
            //TODO add error handler
        }
    }
    else{
        erase_flash(beginAddress, endAddress);
    }
}