*This project has been created as part of the 42 curriculum by bkantoro.*

# FT\_PRINTF
 
## Description

ft\_printf is a 42 project is the project that (partly) recreates libc's printf.
we have to recreate the behaviour or ```cspdiuxX%``` flags. 
the main part of the project is kinda straigtforward, the bonus part is not. 
it requires the handling of `-0.` and `# +` flags.
libft is allowed in the project and is provided along with it. 

so, what we are doing here is
- passing a string and arbitrarz number of arguments to the function
- reading the arguments in a list
- if we met a percent sign, we try to match arguments with flags, passing them with a correct type to print fns.
- thats mainly all about the main part, the only hard thing in it is to convert bases

- but if we try to go for bonus, things become interesting

- `-` flag forces us to justifz output to the left
- `0` pads the number with leading zeros. eg. %05d, 8 -> 00008
- `.` flag is a precision flag. 
	- for integers, it specifies the minumum number of digits to appear
- `#' is an 'alternate form' flag
	- for hex, it prefixes non-zero (ONLY NON-ZERO) results with 0x / 0X
- `+` flag forces positive numbers start with the plus sign
- ' ' flag does the same but positive numbers start with space (nicely padded)

and they are combining... 
- if plus and space are given, plus wins and kills the space flag
- but space works works with zeros.
- also space works with left-justify

and so on. this is crazy. 
i didn't like it at all. 



## Instructions
This project is using Makefile.
so you should run it with `make`, recompile with `make re`. There are also other standarsd 42's rules for make.
To run `make test` you will need your own main.c - or grab mine from `git checkout dev`
Compared to get\_next\_line, this project doesn't require to make separte files for bonus.
So, while we have `make bonus`, it does the same as `make all`.


## Resources
- [oceano's video on printf](https://www.youtube.com/watch?v=kM-DOhKR080)
- [Tripouille's tester](https://github.com/Tripouille/printfTester.git)
- [cpprefence on printf](https://cplusplus.com/reference/cstdio/printf/)
- a lot of peer talks to understand the bonus part
- a lot of Gemini talks to understand the quirks of flag behavior
- Claude Code to generate most of my own tests
- man pages on variadic funtions, e.g. [va\_list](https://man7.org/linux/man-pages/man3/va_list.3type.html)
