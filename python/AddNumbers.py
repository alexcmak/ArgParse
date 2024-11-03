import argparse

#
# This program demonstrates the python standard argparse
#
# Alex Mak

def main():
	descStr = "This program adds two numbers."
	parser = argparse.ArgumentParser(description=descStr)

	parser.add_argument("x", type=int, help="number 1")
	parser.add_argument("y", type=int, help="number 2")
	parser.add_argument('-f', dest='outFile', required=False)
	parser.add_argument('-v', action='store_true')

	args = parser.parse_args()

	answer = args.x + args.y
	verbose_answer = f"{args.x} + {args.y} equals {answer}.\n"

	response = answer

	if args.v:
		response = verbose_answer
	
	if args.outFile:
		f = open(args.outFile, "w")
		f.write(str(response))
		f.close()
	else:
		print(response)


if __name__ == '__main__':
	main()