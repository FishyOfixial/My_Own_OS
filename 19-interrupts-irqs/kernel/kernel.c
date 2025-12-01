#include "../drivers/screen.h"
#include "util.h"
#include "../cpu/isr.h"
#include "../cpu/idt.h"

// Handler del timer IRQ0
void timer_callback(registers_t r) {
    static int tick = 0;
    tick++;
    kprint("Tick!\n");
}

void main() {
    // Instalar ISRs y remapear IRQs
    isr_install();

    // Registrar handler del timer
    register_interrupt_handler(32, timer_callback);

    // Inicializar PIT para que el timer genere IRQ0
    init_timer(18);  // 18 ticks por segundo (~55ms)

    // Test de interrupciones ISRs
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");

    // Mensaje inicial
    kprint("Kernel loaded!\n");

    // Loop infinito para mantener el kernel corriendo
    while (1) {
        // HLT para ahorrar CPU
        __asm__ __volatile__("hlt");
    }
}
