#pragma once

#include "disassembler.hpp"

bool DisassembleSH2(Disassembler &disasm, std::string_view origin, const std::vector<std::string> &args,
                    const std::string &inputFile);
