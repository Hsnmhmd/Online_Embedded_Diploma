
//startup.c
//Eng. Hassan

#include <stdint.h>
extern int main(void);

void Reset_Handler();
void NMI_Handler()__attribute__((weak, alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak, alias("Default_Handler")));
//Booking 1024 B located in .bss through unitialized array of int 256 Elemet
/*It is static to avoid any possible mis use of the name*/
static unsigned long Stack_top[256];

	
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
extern unsigned int _E_text;
extern unsigned int _stack_top;

void Default_Handler(){
	Reset_Handler();
}

/*Array of pointers to functions take nothing and return void
 instead of the array of the addresses
 We put it at the start of the flash*/
void  (* const g_p_fn_Vectors[])()__attribute__((section(".vectors"))) =
{
	(void(*)()) ((unsigned long)Stack_top+sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
};

void Reset_Handler(){
	/* Coping data from ROM T RAM*/
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	for(int i = 0; i < DATA_size; i++){
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	/* Initializing bss Section*/
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss ;
	for(int i = 0; i < bss_size; i++){
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	} 
	
	/* Jumping To main */
	main(); 
	
}