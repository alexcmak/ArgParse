using CommandLine;

namespace AddNumbers
{
    class Options
    {
        [Option('x', Required = true, HelpText = "x")]
        public int x { get; set; }

        [Option('y', Required = true, HelpText = "y")]
        public int y { get; set; }

        [Option('f', Required = false, HelpText = "Write to output file")]
        public string outFile { get; set; }

        [Option('v', Required = false, HelpText = "Verbose mode")]
        public bool bVerbose { get; set; }
    }
}
