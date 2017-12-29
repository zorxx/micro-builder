import os
import argparse

def PadFile(in_file, out_file, length):
	f_in = open(in_file, 'rb')
	f_out = open(out_file, 'wb')
	while 1:
		buf = f_in.read(1024 * 1024)
		if not buf:
			break
		f_out.write(buf)
	curlen = f_in.tell()
	f_in.close()
	if(curlen < length):
		addlen = length - curlen
		pad = "\0" * addlen
		f_out.write(pad)
	f_out.close()

if __name__=='__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument('in_file', type=str, action='store')
	parser.add_argument('out_file', type=str, action='store')
	parser.add_argument('final_length', type=int, action='store')
	args = parser.parse_args()
	PadFile(args.in_file, args.out_file, args.final_length)
