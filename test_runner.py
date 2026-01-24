import subprocess

input_file = "input.txt"
output_file = "outputInterOp.txt"

command = ["./srps", input_file, output_file]

result = subprocess.run(
    command,
    capture_output=True,
    text=True
)

print("Return code:", result.returncode)
print("STDOUT:\n", result.stdout)
print("STDERR:\n", result.stderr)
