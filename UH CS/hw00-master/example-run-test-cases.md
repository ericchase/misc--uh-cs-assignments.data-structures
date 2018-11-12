# Example of running a program with test cases

The steps assume that you are already logged-in to the linux server.

## Compile your code and run it

1. The starting point is after that you login to the linux server.

   ```bash
   [username@linuxserver ~]$
   ```
   
   We type `ls` (to list contents of current folder), and see our `hw0` folder (among other folders, if any).
   
    ```bash
    [username@linuxserver ~]$ ls
    hw0
    [username@linuxserver ~]$
    ```

1. Get all the test cases of **hwZero** via cloning the repo (at GitHub).

   Make a new folder to keep GitHub repositories. Then go inside of that folder.
   
    ```bash
    [username@linuxserver ~]$ mkdir gitstuff
    [username@linuxserver ~]$ cd gitstuff
    [username@linuxserver gitstuff]$ 
    ```

   In a web-browser, go to the [hwZero repo](https://github.com/uhcs2320/hwZero), click on **Clone or download** 
   and copy the link, which should be: `https://github.com/uhcs2320/hwZero.git`

    Back in the terminal, do a `git clone` command to clone the repo. Here you'll **paste** (or type) the "git" link of the repo.
   
    ```bash
    [username@linuxserver gitstuff]$ git clone https://github.com/uhcs2320/hwZero.git
    ```

   The output from such command would look like this:

    ```bash
    Cloning into 'hwZero'...
    remote: Counting objects: 183, done.
    remote: Total 183 (delta 0), reused 0 (delta 0), pack-reused 183
    Receiving objects: 100% (183/183), 20.60 KiB | 0 bytes/s, done.
    Resolving deltas: 100% (73/73), done.
    [username@linuxserver gitstuff]$ 
    ```

    Git cloned the repo. You should have a new folder (named hwZero), see it listed via `ls`

    ```bash
    [username@linuxserver gitstuff]$ ls
    hwZero
    [username@linuxserver gitstuff]$ 
    ```

    Inside of folder `hwZero` there will be a sub-folder with test cases. Go into such folder.

    ```bash
    [username@linuxserver gitstuff]$ cd hwZero
    [username@linuxserver hwZero]$ cd test-cases
    [username@linuxserver test-cases]$ 
    ```

    List all the test cases via `ls`

    ```bash
    [username@linuxserver test-cases]$ ls
     output           test1-b.input1   test1-d.input1  test1-f.output  test1-i.input1  test1-k.output  test1-n.input1  test1-p.output  test1-s.input1
     test1-aa.input1  test1-b.output   test1-d.output  test1-g.input1  test1-i.output  test1-l.input1  test1-n.output  test1-q.input1  test1-s.output
     test1-a.input1   test1-cc.input1  test1-e.input1  test1-g.output  test1-j.input1  test1-l.output  test1-o.input1  test1-q.output  test1-t.input1
     test1-a.output   test1-c.input1   test1-e.output  test1-h.input1  test1-j.output  test1-m.input1  test1-o.output  test1-r.input1  test1-t.output
     test1-bb.input1  test1-c.output   test1-f.input1  test1-h.output  test1-k.input1  test1-m.output  test1-p.input1  test1-r.output
    ```

    Please note that you do not have to use these GitHub steps. 
    You could download each file separately as well.  

1. Compile your code in the same place where the test cases are located.
At this point, you are in the same folder where the test cases are located. 
One easy option is to copy your `cpp` files here and test your code here.
 This can be done from the `hw0` folder in your home directory in linux (for which `~` is an alias).

    The following command will copy all `cpp` from folder `hw0` to the current folder (which happens to be: test-cases).

    ```bash
    [username@linuxserver test-cases]$ cp -i ~/hw0/*cpp .
    [username@linuxserver test-cases]$ 
    ```

    (I always use the `-i` **interactive** flag so that I get a confirmation prompt that shows up to confirm whether you want to overwrite a file).

    Then compile the code as usual. For the **hw0** assignment, it would be like this:

    ```bash
    [username@linuxserver test-cases]$ g++ -std=c++11 -o uhday -I ./ *.cpp
    [username@linuxserver test-cases]$ 
    ```
    
1. Run your code with one input file for now.

    ```bash
    [username@linuxserver test-cases]$ ./uhday "input=test1-g.input1"
    Minutes: 1
    Hours: 1
    Days: 0
    [username@linuxserver test-cases]$ 
    ```

1. Things look good. Redirect the output into a file, named `my-output.g.txt`

    ```bash
    [username@linuxserver test-cases]$ ./uhday "input=test1-g.input1" > my-output.g.txt
    [username@linuxserver test-cases]$ 
    ```
    
    View the contents of the file just created:

    ```bash
    [username@linuxserver test-cases]$ cat my-output.g.txt
    Minutes: 1
    Hours: 1
    Days: 0
    [username@linuxserver test-cases]$ 
    ```

1. Use `diff` so that linux helps us to see whether this file is a match with the one used in automated grading.

    ```bash
    [username@linuxserver test-cases]$ diff my-output.g.txt test1-g.output
    1,3c1,3
    < Minutes: 1
    < Hours: 1
    < Days: 0
    ---
    > Minutes:1
    > Hours:1
    > Days:0
    [username@linuxserver test-cases]$ 
    ```

    Unfortunately, our program outputs an extra space, which causes a failed test case. 

1. This can be done a bit faster via **pipe** of the output of our program into `diff`.
 We just need to tell `diff` that instead of one of the files, it needs to read from standard input.
 The output of the program will be "piped" into `diff`. Note the use of `-` in `diff` to make this happen.

    ```bash
    [username@linuxserver test-cases]$ ./uhday "input=test1-g.input1" | diff - test1-g.output
    1,3c1,3
    < Minutes: 1
    < Hours: 1
    < Days: 0
    ---
    > Minutes:1
    > Hours:1
    > Days:0
    [username@linuxserver test-cases]$ 
    ```

    The program still has an error but I can compare the output of the program with the "perfect" output of the test case without having to use an intermediate file (as I did with file my-output.g.txt in previous steps).

1. If before the due date, fix the program and try again.

    I edited the `.cpp` file, recompiled it, and tried again:

    ```bash
    [username@linuxserver test-cases]$ ./uhday "input=test1-g.input1" | diff - test1-g.output
    [username@linuxserver test-cases]$ 
    ```
    
    The lack of any output (by `diff`) means that the output of my program was the same as that of the file `test1-g.output`

1. Keep comparing other input files and their respective output with the output produced by my program.

    There are 20 test cases for hw0. Try each of them.

    ```bash
    [username@linuxserver test-cases]$ ./uhday "input=test1-a.input1" | diff - test1-a.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-b.input1" | diff - test1-b.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-c.input1" | diff - test1-c.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-d.input1" | diff - test1-d.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-e.input1" | diff - test1-e.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-f.input1" | diff - test1-f.output
    [username@linuxserver test-cases]$ ./uhday "input=test1-g.input1" | diff - test1-g.output
    [username@linuxserver test-cases]$ 
    ```

    Nice! no errors so far, but this is getting a tiny bit tedious/annoying.

1. Use a `for` loop (in linux command-prompt) to help with the testing.

    ```bash
    [username@linuxserver test-cases]$ for A in a b c d e f g ; do ./uhday "input=test1-${A}.input1" | diff - test1-${A}.output ; done
    [username@linuxserver test-cases]$ 
    ```

    Nice! no errors when testing 7 of the test cases. Test all of them then.

    ```bash
    [username@linuxserver test-cases]$ for A in a b c d e f g h i j k l m n o p q r s t ; do ./uhday "input=test1-${A}.input1" | diff - test1-${A}.output ; done
    2c2
    < Hours:113
    ---
    > Hours:89
    1,2c1,2
    < Minutes:100
    < Hours:71
    ---
    > Minutes:0
    > Hours:37
    1c1
    < Minutes:40
    ---
    > Minutes:0
    [username@linuxserver test-cases]$ 
    ```

    Oh no! something failed somewhere!
    We should add a few `echo` lines to find out what test cases failed.
    
    ```bash
    [username@linuxserver test-cases]$ for A in a b c d e f g h i j k l m n o p q r s t ; do echo "Test case: $A"; ./uhday "input=test1-${A}.input1" | diff - test1-${A}.output ; echo "" ; done
    Test case: a
    
    Test case: b
    
    Test case: c
    
    Test case: d
    
    Test case: e
    
    Test case: f
    
    Test case: g
    
    Test case: h
    
    Test case: i
    
    Test case: j
    
    Test case: k
    2c2
    < Hours:113
    ---
    > Hours:89
    
    Test case: l
    
    Test case: m
    
    Test case: n
    
    Test case: o
    1,2c1,2
    < Minutes:100
    < Hours:71
    ---
    > Minutes:0
    > Hours:37
    
    Test case: p
    
    Test case: q
    1c1
    < Minutes:40
    ---
    > Minutes:0
    
    Test case: r
    
    Test case: s
    
    Test case: t
    
    [username@linuxserver test-cases]$ 
    ```
    
    Why am I failing test case q?

    ```bash
    [username@linuxserver test-cases]$ cat test1-q.input1
    
    The student reads 40K minutes every day

    It took 12.67 minutes to form an opinion

    No one said anything in 654 days
    
    [username@linuxserver test-cases]$ 
    ```
    
    I see, my program is reading `40K` as number `40`.
