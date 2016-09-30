from subprocess import Popen, PIPE
import os
import shutil
import time
import sys
import filecmp

if __name__ == "__main__":
	#Copy files
	try:
		os.mkdir("tmp")
	except:
		print("Folder exists")
	os.chdir("tmp")
	shutil.copy2("../../bin/server","server")
	shutil.copy2("../../bin/client","client")
	tests = ["test1.txt", "test2.txt", "test3.txt"]
	for test in tests:
		shutil.copyfile("../%s" % test, "%s" % test)
		cmd = "./server 8080".split()
		try:
			server = Popen(cmd, stdout = PIPE, stderr = PIPE)
		except:	
			print(sys.exc_info()[0])
		cmd = ("./client localhost 8080 %s" % test).split(" ")
		try:
			client = Popen(cmd, stdout = PIPE, stderr = PIPE)
			out, err = client.communicate()
			print err
		except :
			server.kill()
			print(sys.exc_info()[0])
			print "aaaa"

		time.sleep(2);	
		server.kill()	
		if err:
			print("%s failed" % test)
			sys.exit(1)
		if not filecmp.cmp(test,"out.txt"):
			print("%s failed" % test)
			sys.exit(1)
			
		os.remove("out.txt")
	os.chdir("../")
	shutil.rmtree("tmp")
