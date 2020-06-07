from django.shortcuts import render
from django.http import HttpResponse
from background_task import background
import time
from . import tasks
# Create your views here.
#import subprocess,os,resource,sys


def indexView(request):
    tasks.hello()
    return HttpResponse("Halum taken")
