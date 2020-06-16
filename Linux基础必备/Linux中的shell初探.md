> 进入企业后，大部分情况都是Linux操作系统，那么熟悉命令的用法以外，熟悉使用shell脚本也是让我们有更多时间摸鱼的好办法(ps面试要注意哦)，开整！

## 1 shell是什么

> 平时经常在Linux操作系统中使用各种命令，比如查看当前的目录文件，我们会使用"ls"或者"ls -l"，这些字符串参数实际上会被"某段程序"执行并启动它。这个负责将用户输入的字符串转换为需要执行程序的东西叫做"shell"。即帮用户更方便使用操作系统接口的“壳”。同样的壳还有当我输入Maven+相关参数的时候是不是就会去执行相应的功能，我们驶入sql语句的时候，数据库引擎是不是也会各种调用，一样的道理

## 2 尝试编写第一个shell

> vim创建打开一个文件，扩展名为.sh。如下所示

```shell
#!/bin/bash #告诉系统使用什么解析器
echo "Hello xiaolan !" # echo进行输出
```

- 执行方法1

> chmod +x ./hello.sh
>
> ./hello.sh 

- 执行方法2

> /bin/sh hello.sh

## 3 变量

> 变量名和等号之间不能有空格

定义变量注意事项

- 命名首个字符不能是数字，只能使用英文字母、数字和下划线
- 不能使用标点符号
- 不能使用bash中关键字

变量使用

> 使用变量(使用变量的过程中，最好加上花括号)，只需要在变量前面加上美元符号即可

```shell
#!/bin/bash
James="小皇帝"
echo $James
```

只读变量

> 使用readonly将变量定义为只读，只读意味着不能改变

```shell
#!/bin/bash
James="小皇帝"
readonly James
James="登哥"
```

删除变量

> 使用unset删除变量 变量删除以后不能再次使用，且不能删除只读变量

```shell
#!/bin/bash
James="小皇帝"
unset James
echo $James #不会有任何输出
```

变量类型

- 局部变量

> 仅当前shell可用

- 环境变量

> 所有程序都能访问环境变量

- shell变量

> 通过一部分环境变量和shell变量保证shell的正常运行

## 4 字符串

> 使用字符串的过程中，既可以用双引号也可以用单引号，也可以不用

- 单引号

> 单引号内容原样输出，不能包含变量，且不能出现单独单引号

- 双引号

> 可以出现转义字符

```shell
#!/bin/bash
James="小皇帝"
str="\"$ James\"! oh my gad \n "
echo -e $str 
```

获取字符串长度

> 使用#

```shell
string="qwert"
echo $(#string)

# 提取子字符串
echo $(string:1:3)
#查找字符串
echo 
```

## 5 数组

> 支持以为数组

定义数组

> 数组元素使用“空格”隔开

```shell
array=(value1,value2,value3)
```

读取数组

```shell
value1=${array[0]}
```

使用@输出数组所有元素

```shell
echo ${array[@]}
```

获取数组中所有元素以及数组长度

```shell
#! /bin/bash
# author：xiaolan
array[0]=a
array[1]=b
array[3]=c

echo “数组的元素为：${array[*]}”
echo “数组的元素为：${array[@]}”
echo “数组的个数为：${#array[*]}”
echo “数组的个数为：${#array[@]}”
```

执行

```shell
./array.sh
```

结果

![](https://imgkr.cn-bj.ufileos.com/25ab2db6-d708-438f-b652-2c0629e7687b.png)

## 6 注释

单行注释

> 使用#开头的行为注释，会被解释器忽略

多行注释

```shell
:<<EOF

EOF
```

## 7 shell传递参数

> 在执行shell的时候，命令行指定参数，如下所示

```shell
#!/bin/bash
James="小皇帝"
echo "执行的文件名为:$0"
echo "第一个参数为:$1"
echo "第二个参数为:$2"
```

执行

```shell
./param.sh 1 2
```

结果

![](https://imgkr.cn-bj.ufileos.com/d7477607-87c4-4fd8-ab10-aecfa844de07.png)

几个特殊字符

![](https://imgkr.cn-bj.ufileos.com/32051b37-8b69-46a2-8f29-39b6eda064ad.png)


案例(partionnal.sh)

```shell
#!/bin/bash
# author:xiaolan

echo "-- \$* 演示 ---"
for i in "$*"; do
    echo $i
done

echo "-- \$@ 演示 ---"
for i in "$@"; do
    echo $i
done
```

执行

```shell
./demo2.sh 1 2 3
```

结果

![](https://imgkr.cn-bj.ufileos.com/de6d54b1-bc71-44af-8952-b8b357aff7d1.png)

$*与$@区别

相同点：都是会引用所有参数

不同点：在使用双引号的时候。如果脚本运行时两个参数为a,b，则"*"等价于"ab",而"@"等价于"a","b"

```shell
#!/bin/bash
# author:xiaolan

echo "-- \$* 演示 ---"
for i in "$*"; do
    echo $i
done

echo "-- \$@ 演示 ---"
for i in "$@"; do
    echo $i
done
```

## 8 printf

> 使用printf格式化字符串，同时可以指定字符串宽度和对齐方式，格式如下

```shell
printf format-string [arguments...]
```

```shell
#!/bin/bash
# author:xiaolan
 
printf "%-8s %-8s %-4s\n" 姓名 科目 分数  
printf "%-8s %-8s %-4f\n" 小明 数学 97
printf "%-8s %-8s %-4f\n" 小话 语文 89
printf "%-8s %-8s %-4f\n" 王三 英语 93
```

结果

![](https://imgkr.cn-bj.ufileos.com/cf5152a4-fe4e-468a-a2c2-631794e7bc9f.png)

## 9 test

> shell中的test用于检查某个条件是否成立


![](https://imgkr.cn-bj.ufileos.com/8bce8230-2eac-41d9-968b-17da9e249f27.png)


案例

```shell
#!/bin/bash
# author:xiaolan
num1=55
num2=55
if test $[num1] -eq $[num2]
then
    echo '两个数相等！'
else
    echo '两个数不相等！'
fi
```

结果

![](https://imgkr.cn-bj.ufileos.com/96b32658-0974-44ee-9d1f-5e334765f765.png)

字符串比较

![](https://imgkr.cn-bj.ufileos.com/1a360780-ad2a-4577-99a6-2f0efc38da14.png)


```shell
#!/bin/bash
# author:xiaolan
num1="xiaolan"
num2="xiaolna"
if test $num1 = $num2
then
    echo '两个字符串相等!'
else
    echo '两个字符串不相等!'
fi
```

结果

![](https://imgkr.cn-bj.ufileos.com/4e89d834-ac70-4523-b491-9e26cd5c194e.png)

## 10 流程

if语句语法格式

```shell
if condition
then
    exec1 
    exec2
    ...
    execN 
fi
```

如果简化为一行

```shell
if [$(ps -ef | grep -c "httpd") -gt 1];then echo "true";fi
```

if else-if else

```shell
if condition1
then
    exec1
elif condition2 
then 
    exec2
else
    execn
fi
```

案例 判断两数值是否相等

```shell
#!/bin/bash
# author:xiaolan
a=2
b=3
if [ $a == $b ]
then
   echo "a 等于 b"
elif [ $a -gt $b ]
then
   echo "a 大于 b"
elif [ $a -lt $b ]
then
   echo "a 小于 b"
else
   echo "没有符合的条件"
fi
```

for循环

```shell
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done
```

while语句

> 通常用于从输入文件不断读取数据

```shell
while condition
do
    exec
done
```

```
#!/bin/bash
# author:xiaolan
int=1
while(( $int<=6 ))
do
    echo $int
    let "int++"# 用于执行一个或者多个
done
```

无限循环

```shell
while true
do
    exec
done
```

case语句

> 多选择语句。取值后面为单词in，每一个模式以")"结束。匹配发现取值符合某一模式后，其间所有命令开始执行直至 ";;"。

```shell
#!/bin/bash
# author:xiaolan
echo '输入 1 到 3 之间的数字:'
echo '你输入的数字为:'
read aNum
case $aNum in
    1)  echo '你选择了 1'
    ;;
    2)  echo '你选择了 2'
    ;;
    3)  echo '你选择了 3'
    ;;
    *)  echo '你没有输入 1 到 3 之间的数字'
    ;;
esac
```

输入不同的内容，会有不同的结果，例如：

```shell
输入 1 到 4 之间的数字:
你输入的数字为:
3
你选择了 3
```

跳出循环

break

> break命令允许跳出所有循环

```shell
#!/bin/bash
# author:xiaolan
while :
do
    echo -n "输入 1 到 3 之间的数字:"
    read aNum
    case $aNum in
        1|2|3) echo "你输入的数字为 $aNum!"
        ;;
        *) echo "你输入的数字不是 1 到 3 之间的! 游戏结束"
            break
        ;;
    esac
done
```

continue

> 跳出当次循环

```shell
#!/bin/bash
while :
do
    echo -n "输入 1 到 3 之间的数字: "
    read aNum
    case $aNum in
        1|2|3|4|5) echo "你输入的数字为 $aNum!"
        ;;
        *) echo "你输入的数字不是 1 到 3 之间的!"
            continue
            echo "游戏结束"
        ;;
    esac
done
```

## 10 shell函数

> 用户定义函数，然后在shell脚本中随便调用，格式如下

```shell
[ function ] funname [()]

{

    action;

    [return int;]

}
```

例子

```shell
#!/bin/bash
# author:xiaolan

Fun1(){
    echo "这是我的第一个 shell 函数!"
}
echo "-----函数开始执行-----"
Fun1
echo "-----函数执行完毕-----"
```

带return语句

```shell
#!/bin/bash
# author:xiaolan

FunReturn(){
    echo "这个函数会对输入的两个数字进行相加运算..."
    echo "输入第一个数字: "
    read aNum
    echo "输入第二个数字: "
    read anotherNum
    echo "两个数字分别为 $aNum 和 $anotherNum !"
    return $(($aNum+$anotherNum))
}
FunReturn
echo "输入的两个数字之和为 $? !"
```

函数参数

```shell
#!/bin/bash
# author:xiaolan

funParam(){
    echo "第一个参数为 $1 !"
    echo "第二个参数为 $2 !"
    echo "参数总数有 $# 个!"
    echo "作为一个字符串输出所有参数 $* !"
}
funParam 1 2 3 4
```

## 11 shell重定向

输出重定向

> command1 > file # 如果file中存在内容将被清空覆盖。如果追加使用command1 >>file

```shell
ls -l > dir.txt
```

cat dir.txt

![](https://imgkr.cn-bj.ufileos.com/8647eb9a-9bba-4a76-9493-a9f4aed332c5.png)


/dev/null文件

> 写入到它的内容都会被丢弃，会起到"禁止输出"的效果，如果希望屏蔽stdout和stderr

> command > /dev/null 2>&1

注意：Linux命令行都会打开三个文件

- 标准输入文件:stdin文件描述符为0
- 标准输出文件:stdout文件描述符为1
- 标准错误文件:stderr文件描述符2

## 12 运算符

下表列出了常用的算术运算符，假定变量 a 为 2，变量 b 为 3：

算术运算符

![](https://imgkr.cn-bj.ufileos.com/eee390f8-4442-49ba-b0f9-d668c4279f73.png)

关系运算符

![](https://imgkr.cn-bj.ufileos.com/21470c80-5054-4ba5-baeb-e735bbca1ff8.png)


布尔运算符

![](https://imgkr.cn-bj.ufileos.com/4900a496-2c23-4fda-85a7-ae143995fdf7.png)


逻辑运算符

![](https://imgkr.cn-bj.ufileos.com/34731d51-2610-4b8d-a266-eb77f87f7ac6.png)


字符串运算符

![](https://imgkr.cn-bj.ufileos.com/c4755a36-133c-4377-b28d-dc8d4725c473.png)
       

## 12 高频面试(笔试)shell实战

- 请将当前目录中demo.txt第二行第三列数据输出到demo2.txt中

> cat demo.txt|awk ’NR==2{print $3}’ >demo2.txt

- 日志如下统计访问ip最多的前10个

> awk ’{print $1}’ *.log | sort | uniq -c | sort -nr | head -n

uniq - 删除排序文件中的重复行
sort对于文本进行排序
-l 按照当前环境排序.
-m 合并已经排序好的文件,不排序.
-n 按照字符串的数值顺序比较,暗含-b
-r 颠倒比较的结果.

- 查看占用内存最大的进程的PID和VSZ

> ps -aux|sort -k5nr|awk ’BEGIN{print ”PID VSZ”}{print $2,$5}’|awk ’NR<3′

- 如何检查文件系统中是否存在某个文件

```shell
if [-f /var/log/messages]
then
echo "File exts"
fi
```

- 每个脚本开始的 #!/bin/sh 或 #!/bin/bash 表示什么意思 ?

> \#!/bin/bash 表示脚本使用 /bin/bash。对于 python 脚本，就是 #!/usr/bin/python

- &和&&区别

> “&” 脚本在后台运行时使用它。“&&”当前一个脚本成功完成才执行后面的命令

- 脚本文件中，如何将其重定向标准输出和标准错误流到 log.txt 文件 ?

```shell
./a.sh >log.txt 2>&1
```

- 如何计算本地用户的数目

```
wc -l /etc/passwd | cut -d
```

- shell中进行字符串比较和数字比较

```
[ $A == $B ] – 用于字符串比较
[ $A -eq $B ] – 用于数字比较
```

- 去掉字符串空格

>echo $string | tr -d " "

- 统计内存使用

```shell
#! /bin/bash
# author:xiaolan
sum=0
for mem in `ps aux |awk '{print $6}' |grep -v 'RSS' `
do
    sum=$[$sum+$mem]
done
echo "The total memory is $sum""k"
```

结果

![](https://imgkr.cn-bj.ufileos.com/4d9b283b-efda-44ce-9f39-4bbc876fe630.png)

- 批量更改文件名

> 批量修改123目录下txt为txt.temp。将temp打包为test.tar.gz

```shell
#!/bin/bash
##查找txt文件
find /123 -type f -name "*.txt" > /tmp/txt.list
##批量修改文件名
for f in `cat /tmp/txt.list`
do
    mv $f $f.temp
done
##创建一个目录，为了避免目录已经存在，所以要加一个复杂的后缀名
d=`date +%y%m%d%H%M%S`
mkdir /tmp/123_$d
##把.temp文件拷贝到/tmp/123_$d
for f in `cat /tmp/txt.list`
do
    cp $f.temp /tmp/123_$d
done
##打包压缩
cd /tmp/
tar czf 123.tar.gz 123_$d/
```
> 本文主要记录shell编程初级知识，获取更多消息请关注下方公众号。

</p>
    <img src="https://imgkr.cn-bj.ufileos.com/a896c66c-70fb-435a-8f57-f257ae6b7d16.jpg" align="right" width="200px">
</div>