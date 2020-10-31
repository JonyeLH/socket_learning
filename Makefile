#是注释
#第一层：显示规则
#目标文件：依赖文件
#[TAB]指令
#
#第一个目标文件是我的最终文件!!!递归
#
#rm -rf hello hello.o hello.S hello.i	没有目标文件的指令——伪目标
#伪目标： .PHONY:
hello:hello.o
	gcc hello.o -o hello

hello.o:hello.S
	gcc -c hello.S -o hello.o	

hello.S:hello.i
	gcc -S hello.i -o hello.S
	
hello.i:hello.c
	gcc -E hello.c -o hello.i
	
.PHONY:
clear:
	rm -rf hello hello.o hello.S hello.i



	
	
	
	
	
	
	
	
	