section .text
    global check_if_vm

check_if_vm:
    mov eax, 0x40000000 ; Query hypervisor information
    cpuid
    ; If it's a VM, the registers ebx, ecx, edx will contain a string
    ; For KVM: "KVMKVMKVM"
    ; For VirtualBox: "VBoxVBoxVBox"
    
    cmp ebx, 0x4b4d564b ; Checks for "KVMK" (little endian)
    je is_vm
    mov rax, 0          ; Return 0 (False - Physical Machine)
    ret

is_vm:
    mov rax, 1          ; Return 1 (True - Virtual Machine)
    ret
