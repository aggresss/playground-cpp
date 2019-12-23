
GCC-5.3 documentation says:

- -fstack-protector
Emit extra code to check for buffer overflows, such as stack
smashing attacks. This is done by adding a guard variable to functions
with vulnerable objects. This includes functions that call alloca, and
functions with buffers larger than 8 bytes. The guards are initialized
when a function is entered and then checked when the function exits.
If a guard check fails, an error message is printed and the program exits.

- -fstack-protector-all
Like -fstack-protector except that all functions are protected.

- -fstack-protector-strong
Like -fstack-protector but includes additional functions to be
protected — those that have local array definitions, or have
references to local frame addresses.

