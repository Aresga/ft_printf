## notes 

In the context of C programming and creating a library similar to the C standard library, the function you're talking about is most likely the **`ft_printf`** function, which replicates the behavior of the `printf` function. 

The **`printf`** function uses format specifiers (like `%d`, `%s`, etc.) to print different types of arguments. When implementing `ft_printf`, you need to handle these specifiers correctly. Here's an explanation of each specifier you mentioned:

### 1. **`%c` (Character)**
   - Prints a single character.
   - Example: 
     ```c
     ft_printf("%c", 'A'); // Output: A
     ```

### 2. **`%s` (String)**
   - Prints a null-terminated string of characters.
   - Example:
     ```c
     ft_printf("%s", "Hello"); // Output: Hello
     ```

### 3. **`%p` (Pointer)**
   - Prints a pointer's memory address in hexadecimal format, usually prefixed with `0x`.
   - Example:
     ```c
     int a = 10;
     ft_printf("%p", &a); // Output: 0x7ffee91b4c34 (example address)
     ```

### 4. **`%d` and `%i` (Signed Integer)**
   - Prints a signed integer in decimal (base 10) format.
   - `%d` and `%i` behave identically for `printf`.
   - Example:
     ```c
     ft_printf("%d", 42);   // Output: 42
     ft_printf("%i", -42);  // Output: -42
     ```

### 5. **`%u` (Unsigned Integer)**
   - Prints an unsigned integer in decimal (base 10) format.
   - Example:
     ```c
     ft_printf("%u", 3000000000); // Output: 3000000000
     ```

### 6. **`%x` and `%X` (Hexadecimal Integer)**
   - Prints an unsigned integer in hexadecimal format.
   - `%x` uses lowercase letters (`abcdef`), and `%X` uses uppercase letters (`ABCDEF`).
   - Example:
     ```c
     ft_printf("%x", 255);  // Output: ff
     ft_printf("%X", 255);  // Output: FF
     ```

### 7. **`%%` (Percent Sign)**
   - Prints a literal percent sign (`%`).
   - Example:
     ```c
     ft_printf("%%"); // Output: %
     ```

### **Implementation Tips**
- **Variadic Functions:** You need to use `va_list` to handle the variable number of arguments in `ft_printf`.
  ```c
  va_list args;
  va_start(args, format);
  ```

- **Type Handling:** Use `va_arg` to retrieve the argument based on the specified type.
  ```c
  char c = va_arg(args, int);   // For %c
  char *s = va_arg(args, char*); // For %s
  int d = va_arg(args, int);    // For %d, %i
  unsigned int u = va_arg(args, unsigned int); // For %u, %x, %X
  ```

- **Hexadecimal Conversion:** Implement a helper function to convert integers to hexadecimal strings.

### Example Code Snippet for `%c` and `%s`
```c
void handle_c(va_list args) {
    char c = va_arg(args, int);
    write(1, &c, 1);
}

void handle_s(va_list args) {
    char *str = va_arg(args, char *);
    if (str == NULL)
        str = "(null)";
    write(1, str, ft_strlen(str));
}
```


You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.