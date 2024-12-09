import subprocess

# test dap's mutable resolve
proc = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
while True:
    output = proc.stdout.readline()
    if output == '' and proc.poll() is not None:
        break
    if output:
        print(output.strip())
return_code = proc.poll()
if return_code!= 0:
    print(f"执行命令出错，返回码：{return_code}")