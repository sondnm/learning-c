# learning-c
Learning C for the sake of learning C 

## Docker for C development

```
docker build -t cdev .
docker run -it --rm -v (pwd):/home --cap-add=SYS_PTRACE --security-opt seccomp=unconfined cdev
```
