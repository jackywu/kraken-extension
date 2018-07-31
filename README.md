Kraken Extension
===============================================

This project has some utility software for kraken-1.0, which will make your life better.

- db_keeper: mmap database.kdb and database.idx, and then hold it in RAM forever until process quit.

use "-h" suffix to show help like this.

        ➜  kraken.bin ./db_keeper -h
        Missing mandatory option -d
        Usage: db_keeper -d [KrakenDB] -i [KrakenDBIndex]

        Options: (*mandatory)
        * -d filename      Kraken DB filename
        * -i filename      Kraken DB index filename
          -h               Print this message

run the command like this

        ./db_keeper -d path/to/database.kdb -i path/to/database.idx

if you wanna know how to generate the two files, please refer to [Kraken 2 Manual –](https://ccb.jhu.edu/software/kraken/MANUAL.html).
if you wanna know more about kraken-1.0, this is a blog [kraken源码分析 - JackyWu’s Blog](https://jackywu.github.io/articles/kraken-code-analysis/) tell something about that. 

Kraken taxonomic sequence classification system
===============================================

Please see the [Kraken webpage] or the [Kraken manual]
for information on installing and operating Kraken.
A local copy of the [Kraken manual] is also present here
in the `docs/` directory (`MANUAL.html` and `MANUAL.markdown`).

[Kraken webpage]:   http://ccb.jhu.edu/software/kraken/
[Kraken manual]:    http://ccb.jhu.edu/software/kraken/MANUAL.html
