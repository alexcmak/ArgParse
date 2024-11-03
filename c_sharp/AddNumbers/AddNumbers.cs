using System;
using System.IO;
using CommandLine;

// Simple C# command line program that use CommandLineParser.

namespace AddNumbers
{
    class AddNumbers
    {
        private static void Run(Options opts)
        {
            int answer = opts.x + opts.y;
            string response = answer.ToString();

            if (opts.bVerbose)
                response = String.Format("{0} + {1} is {2}.", opts.x, opts.y, answer);

            if (opts.outFile != null)
            {
                using (StreamWriter out_writer = new StreamWriter(opts.outFile))
                {
                    out_writer.WriteLine(response);
                }
            }
            else
            {
                Console.WriteLine(response);
            }
        }

        static void Main(string[] args)
        {
            Parser.Default.ParseArguments<Options>(args)
               .WithParsed(Run);
        }

    }
}
