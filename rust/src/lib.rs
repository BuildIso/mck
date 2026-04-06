#![no_std]
#![no_main]

#[cfg(not(mck_build))]
#[panic_handler]
fn panic_handler(_: &core::panic::PanicInfo) -> ! {
    loop {}
}

#[no_mangle]
pub extern "C" fn mck_rust_add(a: u32, b: u32) -> u32 {
    a + b
}
