
input:
 first number is the number of characters in a row
 second number is the number of lines (if you are going down 2 rows you will need to round this down to the next lower even number)
 the rest is modified input data (dots are replaced with 1's and hashtags are replaced with 2's) (use a text editor)
 (see the file 'input_bf' for an example)
 
 to change the number of cells you are going down or to the right you will need to modify the code
 
 for the second part run each individually and multiply the results manually
 
 the result (number of trees) will be stored at memory location 12
 
 cells must be able to store numbers larger than about 10500 (set cell size bits to 16 or above)


memory layout:
 empty
 empty
 temp 1
 temp 2
 temp 3
 0
 1
 x
 temp 4
 y (index)
 line length
 remaining lines
 temp 5
 temp 6
 temp 7
 temp 8
 data data data



>>>>>>+>>>>

,>,>>>>>,[>,]  copy input

<[<]  go to start of text


<<<<[  on number of lines

<<  on current y array index
>>>>>[-]<<<<<  clear temp 7
>>>>>>[-]<<<<<<  clear temp 8
[->>>>>+>+<<<<<<]>>>>>[-<<<<<+>>>>>]<<<<<  copy y to temp 8 using temp 7
>>>>>[-]<<<<<  clear temp 7

<<  on x
[->+>>>>>>>+<<<<<<<<]>[-<+>]<  copy (add) x to temp 8 using temp 4  on x


>>>>>>>  on temp 7

>[[-<+>]<>>[-<+>]<<[->>+<<]>><[<+>-]>-]  go to index

>[-<+>]<-
[<<[<]<+>>[>]>-]  if 1 go to start and add 1
>+<

<<[[->>+<<]<]  go back to start and restore array  on temp 6



<<<<  on current y array index

<[-]>  clear temp 4
 add line length to y
>[-<
+  add to y index (add another plus to go down 2)
<+>>]<<[->>+<<]>>>-  decrement line count (add another minus to go down 2)

<<<<  x
+++  add 3 to x (edit accordingly)

<<<<[-]>>>>  clear temp 2  on x
>[-]<  clear temp 4
>>>[-<<+<<<<<+>>>>>>>]<<[->>+<<]<  copy line length to temp 2 using temp 4  on x
<<<[-]>>>  clear temp 3
<<<<<[-]>>>>>  clear temp 1  on x
[-<<<+<<+>>>>>]<<<<<[->>>>>+<<<<<]>>>>>  copy x to temp 3 using temp 1  on x
<<<[-<-[<]>>]>[  compare x and line length
 >  x is larger or equal line length  on x
 <<<[-]>>>  clear temp 3
 >>>[-<<<<<<+<+>>>>>>>]<<<<<<[->>>>>>+<<<<<<]<  copy line length to temp 2 using temp 3  on temp 2
 [->>>>-<<<<]>>>>  subtract line length from x  on x
 <<
]>>

>>>>

]

