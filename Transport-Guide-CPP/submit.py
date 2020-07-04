import os
import shutil
import zipfile

try:
    shutil.rmtree(os.getcwd() + "/Sub")
except OSError as e:
    print ("Error: %s - %s." % (e.filename, e.strerror))
    
try:
    os.mkdir(os.getcwd() + "/Sub")
except OSError as e:
    print ("Error: %s - %s." % (e.filename, e.strerror))
    
try:
    os.remove(os.getcwd() + "/Submit.zip")
except OSError as e:
    print ("Error: %s - %s." % (e.filename, e.strerror))
    
for root, dirs, files in os.walk(os.getcwd() + "/Guide"):  # replace the . with your starting directory
   for file in files:
      path_file = os.path.join(root,file)
      shutil.copy2(path_file, os.getcwd() + "/Sub") # change you destination dir

shutil.copy2(os.getcwd() + "/main.cpp", os.getcwd() + "/Sub") # change you destination dir

shutil.make_archive("Submit", 'zip', os.getcwd() + "/Sub")

try:
    shutil.rmtree(os.getcwd() + "/Sub")
except OSError as e:
    print ("Error: %s - %s." % (e.filename, e.strerror))
