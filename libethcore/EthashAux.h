/*
    This file is part of ethminer.

    ethminer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ethminer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ethminer.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <libdevcore/Worker.h>
#include <ethash/ethash.hpp>

#include "BlockHeader.h"

namespace dev
{
namespace eth
{
struct Result
{
    h256 value;
    h256 mixHash;
};

class EthashAux
{
public:
    static Result eval(int epoch, h256 const& _headerHash, uint64_t _nonce) noexcept;
};

struct WorkPackage
{
    WorkPackage() = default;
    explicit WorkPackage(BlockHeader const& _bh)
      : boundary(_bh.boundary()),
        header(_bh.hashWithout()),
        epoch(ethash::get_epoch_number(static_cast<int>(_bh.number())))
    {}
    explicit operator bool() const { return header != h256(); }

    h256 boundary;
    h256 header;  ///< When h256() means "pause until notified a new work package is available".
    h256 job;
    int epoch = -1;

    uint64_t startNonce = 0;
    int exSizeBits = -1;
    int job_len = 8;
};

struct Solution
{
<<<<<<< HEAD
<<<<<<< HEAD
    uint64_t nonce;
    h256 mixHash;
    WorkPackage work;
    bool stale;
    unsigned index; // Index of the miner(GPU) found the solution
=======
    uint64_t nonce;   // Solution found
    h256 mixHash;     // Mix hash
    WorkPackage work; // WorkPackage this solution refers to
    bool stale;       // Whether or not solution is stale
    unsigned midx;    // Originating miner Id
>>>>>>> 1497942... Embed miner index in solution structure
=======
    uint64_t nonce;                                // Solution found nonce
    h256 mixHash;                                  // Mix hash
    WorkPackage work;                              // WorkPackage this solution refers to
    bool stale;                                    // Whether or not solution is stale
    std::chrono::steady_clock::time_point tstamp;  // Timestamp of found solution
    unsigned midx;                                 // Originating miner Id
>>>>>>> 94f1403... Rework of solution submission
};

}  // namespace eth
}  // namespace dev
