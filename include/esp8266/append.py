import os
import sys
import argparse

def AppendFile(file_list, result):
	f_out = open(result, 'wb')
	for filename in file_list:
		f_in = open(filename, 'rb')
		while 1:
			buf = f_in.read(1024 * 1024)
			if not buf:
				break
			f_out.write(buf)
		f_in.close()
	f_out.close()

if __name__=='__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('in_file', nargs='+', type=str, action='store')
	parser.add_argument('out_file', type=str, action='store')
	args = parser.parse_args()
	AppendFile(args.in_file, args.out_file)
