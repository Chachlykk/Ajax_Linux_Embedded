# HOST
# readelf
ELF Header:<br>
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 <br>
  Class:                             ELF64<br>
  Data:                              2's complement, little endian<br>
  Version:                           1 (current)<br>
  OS/ABI:                            UNIX - System V<br>
  ABI Version:                       0<br>
  Type:                              DYN (Position-Independent Executable file)<br>
  Machine:                           Advanced Micro Devices X86-64<br>
  Version:                           0x1<br>
  Entry point address:               0x11f0<br>
  Start of program headers:          64 (bytes into file)<br>
  Start of section headers:          14392 (bytes into file)<br>
  Flags:                             0x0<br>
  Size of this header:               64 (bytes)<br>
  Size of program headers:           56 (bytes)<br>
  Number of program headers:         14<br>
  Size of section headers:           64 (bytes)<br>
  Number of section headers:         31<br>
  Section header string table index: 30<br>

# ldd
	linux-vdso.so.1 (0x0000725730b55000)<br>
	libc.so.6 => /usr/lib/x86_64-linux-gnu/libc.so.6 (0x0000725730800000)<br>
	/lib64/ld-linux-x86-64.so.2 (0x0000725730b57000)<br>

# size
   text	   data	    bss	    dec	    hex	filename<br>
   2781	    664	     16	   3461	    d85	task04<br>

# strings
/lib64/ld-linux-x86-64.so.2<br>
puts<br>
ctime<br>
__stack_chk_fail<br>
__printf_chk<br>
fopen<br>
stdout<br>
__fprintf_chk<br>
__libc_start_main<br>
__cxa_finalize<br>
fclose<br>
uname<br>
libc.so.6<br>
GLIBC_2.3.4<br>
GLIBC_2.4<br>
GLIBC_2.2.5<br>
GLIBC_2.34<br>
_ITM_deregisterTMCloneTable<br>
__gmon_start__<br>
_ITM_registerTMCloneTable<br>
PTE1<br>
u+UH<br>
ATUSH<br>
L$QH<br>
[]A\<br>
Hostname: %s<br>
Operating system: %s<br>
Hardware platform: %s<br>
Current time: %s<br>
File exists, the output will be written to the end of %s<br>
Can`t open/create the file. Exiting...<br>
9*3$"<br>
GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0<br>
Scrt1.o<br>
__abi_tag<br>
main.c<br>
crtstuff.c<br>
deregister_tm_clones<br>
__do_global_dtors_aux<br>
completed.0<br>
__do_global_dtors_aux_fini_array_entry<br>
frame_dummy<br>
__frame_dummy_init_array_entry<br>
__FRAME_END__<br>
_DYNAMIC<br>
__GNU_EH_FRAME_HDR<br>
_GLOBAL_OFFSET_TABLE_<br>
__libc_start_main@GLIBC_2.34<br>
_ITM_deregisterTMCloneTable<br>
stdout@GLIBC_2.2.5<br>
puts@GLIBC_2.2.5<br>
_edata<br>
fclose@GLIBC_2.2.5<br>
ctime@GLIBC_2.2.5<br>
_fini<br>
__stack_chk_fail@GLIBC_2.4<br>
uname@GLIBC_2.2.5<br>
__data_start<br>
__gmon_start__<br>
__dso_handle<br>
_IO_stdin_used<br>
_end<br>
__bss_start<br>
main<br>
__printf_chk@GLIBC_2.3.4<br>
fopen@GLIBC_2.2.5<br>
__TMC_END__<br>
__fprintf_chk@GLIBC_2.3.4<br>
_ITM_registerTMCloneTable<br>
__cxa_finalize@GLIBC_2.2.5<br>
_init<br>
print_info<br>
.symtab<br>
.strtab<br>
.shstrtab<br>
.note.gnu.build-id<br>
.interp<br>
.gnu.hash<br>
.dynsym<br>
.dynstr<br>
.gnu.version<br>
.gnu.version_r<br>
.rela.dyn<br>
.rela.plt<br>
.init<br>
.plt.got<br>
.plt.sec<br>
.text<br>
.fini<br>
.rodata<br>
.eh_frame_hdr<br>
.eh_frame<br>
.note.gnu.property<br>
.note.ABI-tag<br>
.init_array<br>
.fini_array<br>
.dynamic<br>
.data<br>
.bss<br>
.comment<br>
