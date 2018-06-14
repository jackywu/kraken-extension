/* vim: fileencoding=utf-8 autoindent tabstop=4 shiftwidth=4 expandtab softtabstop=4 filetype=cpp */

#include <iostream>
#include <unistd.h>
#include "kraken_headers.hpp"
#include "krakendb.hpp"
#include "krakenutil.hpp"
#include "quickfile.hpp"
//#include "seqreader.hpp"

using namespace std;
using namespace kraken;


string DB_filename, Index_filename;

void usage(int exit_code) {
  cerr << "Usage: db_keeper -d [KrakenDB] -i [KrakenDBIndex]" << endl
       << endl
       << "Options: (*mandatory)" << endl
       << "* -d filename      Kraken DB filename" << endl
       << "* -i filename      Kraken DB index filename" << endl
       << "  -h               Print this message" << endl
       << endl;
  exit(exit_code);
}

void parse_command_line(int argc, char **argv) {
  int opt;

  if (argc > 1 && strcmp(argv[1], "-h") == 0)
    usage(0);
  while ((opt = getopt(argc, argv, "d:i:")) != -1) {
    switch (opt) {
      case 'd' :
        DB_filename = optarg;
        break;
      case 'i' :
        Index_filename = optarg;
        break;
      default:
        usage(0);
        break;
    }
  }

  if (DB_filename.empty()) {
    cerr << "Missing mandatory option -d" << endl;
    usage(0);
  }
  if (Index_filename.empty()) {
    cerr << "Missing mandatory option -i" << endl;
    usage(0);
  }
}

int main(int argc, char **argv) {
    parse_command_line(argc, argv);
    cerr << "Loading database... " << endl;
    QuickFile db_file;
    db_file.open_file(DB_filename);
    db_file.load_file();
    cerr << "Loading KrakenDB success."<< endl;

    QuickFile idx_file;
    idx_file.open_file(Index_filename);
    idx_file.load_file();
    cerr << "Loading KrakenDBIndex success." << endl;

    cerr << "complete." << endl;
    cerr << "holding db forever." << endl;
    while (1) {
        sleep(86400);
    }
}
