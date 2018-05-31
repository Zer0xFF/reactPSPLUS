#include "types.h"

uint64_t __readmsr(unsigned long __register)
{
	unsigned long __edx;
	unsigned long __eax;
	__asm__ ("rdmsr" : "=d"(__edx), "=a"(__eax) : "c"(__register));
	return (((uint64_t)__edx) << 32) | (uint64_t)__eax;
}

void resetTime()
{
	uint8_t* kernel_base = (uint8_t*)(__readmsr(0xC0000082) - 0x1C0);
	// (?) sceSblSrtcReset
	void(*sceSblSrtcClearTimeDifference)(uint64_t) = (void*)(kernel_base + 0x634690);
	void(*sceSblSrtcSetTime)(uint64_t*) = (void*)(kernel_base + 0x634090);
	sceSblSrtcClearTimeDifference(15);
	sceSblSrtcSetTime(14861963);
}

int _main(void)
{
	syscall(11, resetTime);
	return 0;
}
