import subprocess,os,resource,sys
from background_task import background
from . import test2

@background(schedule=0)
def hello():
    test2.main()
    