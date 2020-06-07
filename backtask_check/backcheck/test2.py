import subprocess,os,resource,sys


def main():
    
    #li = ["g++","foo.cpp"]
    p = subprocess.check_output(["python","backcheck/compileScript.py","g++","-std=c++17","backcheck/foo.cpp"],universal_newlines=True)
    #out, = p.communicate()
    print(int(p))
    if int(p) != 0 : 
        print("Compilation Error!")
        return 
    else :
        print("Compiled Successfully!")
    
    ppp = subprocess.check_output(["python","backcheck/runner.py","./a.out","backcheck/input.txt","backcheck/output.txt"], universal_newlines=True)
    
    st = ppp.split('\n')
    tm = float(st[1])
    mem = int(st[2])
    print(tm)
    print(mem)
    
    
if __name__ == "__main__":
    main()