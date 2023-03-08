# Dowhile 

    * 新增DOWHILE();

```
    //do STMT while (E)
    void DOWHILE(){
        int dowhileBegin = nextLabel();
        int dowhileEnd = nextLabel();
        emit("(L%d)\n", dowhileBegin);
        skip("do");
        STMT();
        skip("while");
        skip("(");
        int e = E();
        emit("if T%d goto L%d\n", e, dowhileBegin); \\當符合T%d的條件時跳回dowhileBegin(L0)
        emit("if not T%d goto L%d\n", e, dowhileEnd); \\不符合時則跳至dowhileEnd(L1)結束程式
        skip(")");
        skip(";");
        emit("(L%d)\n", dowhileEnd);
    }
```

    * 在STMT中增加，假如下一位讀取到為"do"則進入DOWHILE();
    
```
    // STMT = WHILE | BLOCK | ASSIGN
    void STMT() {
    if (isNext("while"))
        WHILE();
    // else if (isNext("if"))
    //   IF();
    else if (isNext("{"))
        BLOCK();
    else if (isNext("do"))
        DOWHILE();
    else
        ASSIGN();
    }
```

## 執行結果
    * dowhile.c
    
```
    yuzi@LAPTOP-BL9QSBJ6:/mnt/c/Users/user/Desktop/網頁設計/sp111b/HW/hw-2/03a-compiler$ make
    gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler
    yuzi@LAPTOP-BL9QSBJ6:/mnt/c/Users/user/Desktop/網頁設計/sp111b/HW/hw-2/03a-compiler$ ./compiler test/dowhile.c
    i = 10;

    do {
        i = i + 1;
    }while( i < 20 );

    ========== lex ==============
    token=i
    token==
    token=10
    token=;
    token=do
    token={
    token=i
    token==
    token=i
    token=+
    token=1
    token=;
    token=}
    token=while
    token=(
    token=i
    token=<
    token=20
    token=)
    token=;
    ========== dump ==============
    0:i
    1:=
    2:10
    3:;
    4:do
    5:{
    6:i
    7:=
    8:i
    9:+
    10:1
    11:;
    12:}
    13:while
    14:(
    15:i
    16:<
    17:20
    18:)
    19:;
    ============ parse =============
    t0 = 10
    i = t0
    (L0)
    t1 = i
    t2 = 1
    t3 = t1 + t2
    i = t3
    t4 = i
    t5 = 20
    t6 = t4 < t5
    if T6 goto L0
    if not T6 goto L1
    (L1)
```
    
    * dowhile2.c
    
```
    yuzi@LAPTOP-BL9QSBJ6:/mnt/c/Users/user/Desktop/網頁設計/sp111b/HW/hw-2/03a-compiler$ ./compiler test/dowhile2.c
    do {
        i = 5;
        i = i + 1;
    }while( i < 10 );

    ========== lex ==============
    token=do
    token={
    token=i
    token==
    token=5
    token=;
    token=i
    token==
    token=i
    token=+
    token=1
    token=;
    token=}
    token=while
    token=(
    token=i
    token=<
    token=10
    token=)
    token=;
    ========== dump ==============
    0:do
    1:{
    2:i
    3:=
    4:5
    5:;
    6:i
    7:=
    8:i
    9:+
    10:1
    11:;
    12:}
    13:while
    14:(
    15:i
    16:<
    17:10
    18:)
    19:;
    ============ parse =============
    (L0)
    t0 = 5
    i = t0
    t1 = i
    t2 = 1
    t3 = t1 + t2
    i = t3
    t4 = i
    t5 = 10
    t6 = t4 < t5
    if T6 goto L0
    if not T6 goto L1
    (L1)
```

# Compiler

## 語法

```
PROG = STMTS
BLOCK = { STMTS }
STMTS = STMT*
STMT = WHILE | BLOCK | ASSIGN
WHILE = while (E) STMT
ASSIGN = id '=' E;
E = F (op E)*
F = (E) | Number | Id
```

## 執行結果

```
user@DESKTOP-96FRN6B MINGW64 /d/ccc/book/sp/code/c/02-compiler/03-compiler
$ make clean
rm -f *.o *.exe

user@DESKTOP-96FRN6B MINGW64 /d/ccc/book/sp/code/c/02-compiler/03-compiler
$ make
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler

user@DESKTOP-96FRN6B MINGW64 /d/ccc/book/sp/code/c/02-compiler/03-compiler
$ ./compiler test/while.c
while (i<10) i = i + 1;

========== lex ==============
token=while
token=(
token=i
token=<
token=10
token=)
token=i
token==
token=i
token=+
token=1
token=;
========== dump ==============
0:while
1:(
2:i
3:<
4:10
5:)
6:i
7:=
8:i
9:+
10:1
11:;
============ parse =============
(L0)
t0 = i
t1 = 10
t2 = t0 < t1
goto L1 if T2
t3 = i
t4 = 1
t5 = t3 + t4
i = t5
goto L0
(L1)
``` 