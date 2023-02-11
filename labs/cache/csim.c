#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cachelab.h"

#define MAX_FILENAME_LEN 128

void displayUsage(int verbose) {
    puts("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>");
    if (!verbose) return;
    puts("Options:");
    puts("  -h         Print this help message.");
    puts("  -v         Optional verbose flag.");
    puts("  -s <num>   Number of set index bits.");
    puts("  -E <num>   Number of lines per set.");
    puts("  -b <num>   Number of block offset bits.");
    puts("  -t <file>  Trace file.");
    puts("");
    puts("Examples:");
    puts("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace");
    puts("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace");
}

void showArgs(int setBits, int lineBits, int offsetBits, char* tracefile,
              int verbose) {
    printf("set bits = %d\n", setBits);
    printf("cache line bits per set = %d\n", lineBits);
    printf("block offset bits = %d\n", offsetBits);
    printf("trace file = %s\n", tracefile);
    printf("verbose = %d\n", verbose);
}

int main(int argc, char** argv) {
    if (argc == 1) {
        displayUsage(1);
        exit(1);
    }

    int c;
    int setBits = -1;
    int lineBits = -1;
    int offsetBits = -1;
    char tracefile[MAX_FILENAME_LEN] = "";
    int verbose = 0;

    extern char* optarg;

    while ((c = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (c) {
            case 'h':
                displayUsage(1);
                return 0;
            case 'v':
                verbose = 1;
                break;
            case 's':
                setBits = atoi(optarg);
                break;
            case 'E':
                lineBits = atoi(optarg);
                break;
            case 'b':
                offsetBits = atoi(optarg);
                break;
            case 't':
                strncpy(tracefile, optarg, sizeof(tracefile));
                break;
            default:
                break;
        }
    }

    int argsIncomplete = 0;
    if (setBits < 0) {
        puts("Please specify the number of set bits using -s <num>");
        argsIncomplete = 1;
    }
    if (lineBits < 0) {
        puts("Please specify the number of line per set using -E <num>");
        argsIncomplete = 1;
    }
    if (offsetBits < 0) {
        puts("Please specify the number of block offset bits using -b <num>");
        argsIncomplete = 1;
    }
    if (!tracefile[0]) {
        puts("Please specify the tracefile using -t <file>");
        argsIncomplete = 1;
    }
    if (argsIncomplete) {
        puts("Arguments incomplete!");
        exit(1);
    }
    showArgs(setBits, lineBits, offsetBits, tracefile, verbose);
    // printSummary(0, 0, 0);
    return 0;
}
