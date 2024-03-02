/*
 * Copyright (c) 2013 ARM Limited
 * Copyright (c) 2014-2015 Sven Karlsson
 * Copyright (c) 2019 Yifei Liu
 * Copyright (c) 2020 Barkhausen Institut
 * Copyright (c) 2021 StreamComputing Corp
 * All rights reserved
 *
 * The license below extends only to copyright in the software and shall
 * not be construed as granting a license to any other intellectual
 * property including but not limited to intellectual property relating
 * to a hardware implementation of the functionality of the software
 * licensed hereunder.  You may use the software subject to the license
 * terms below provided that you ensure that this notice is replicated
 * unmodified and in its entirety in all distributions of the software,
 * modified or unmodified, in source code or in binary form.
 *
 * Copyright (c) 2016 RISC-V Foundation
 * Copyright (c) 2016 The University of Virginia
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __ARCH_RISCV_REGS_CAP_HH__
#define __ARCH_RISCV_REGS_CAP_HH__

#include <string>
#include <vector>

#include "cpu/reg_class.hh"
#include "debug/CapRegs.hh"

namespace gem5
{

namespace RiscvISA
{

namespace cap_reg
{

enum : RegIndex
{
    _CZeroIdx, _CRaIdx, _CSpIdx,  _CGpIdx,
    _CTpIdx,   _CT0Idx, _CT1Idx,  _CT2Idx,
    _CS0Idx,   _CS1Idx, _CA0Idx,  _CA1Idx,
    _CA2Idx,   _CA3Idx, _CA4Idx,  _CA5Idx,
    _CA6Idx,   _CA7Idx, _CS2Idx,  _CS3Idx,
    _CS4Idx,   _CS5Idx, _CS6Idx,  _CS7Idx,
    _CS8Idx,   _CS9Idx, _CS10Idx, _CS11Idx,
    _CT3Idx,   _CT4Idx, _CT5Idx,  _CT6Idx,

    NumArchRegs,

    _CUreg0Idx = NumArchRegs,

    NumRegs
};

} // namespace cap_reg

inline constexpr RegClass capRegClass(CapRegClass, CapRegClassName,
        cap_reg::NumRegs, debug::CapRegs);

namespace cap_reg
{

inline constexpr RegId
    CZero = capRegClass[_CZeroIdx],
    CRa = capRegClass[_CRaIdx],
    CSp = capRegClass[_CSpIdx],
    CGp = capRegClass[_CGpIdx],
    CTp = capRegClass[_CTpIdx],
    CT0 = capRegClass[_CT0Idx],
    CT1 = capRegClass[_CT1Idx],
    CT2 = capRegClass[_CT2Idx],
    CS0 = capRegClass[_CS0Idx],
    CS1 = capRegClass[_CS1Idx],
    CA0 = capRegClass[_CA0Idx],
    CA1 = capRegClass[_CA1Idx],
    CA2 = capRegClass[_CA2Idx],
    CA3 = capRegClass[_CA3Idx],
    CA4 = capRegClass[_CA4Idx],
    CA5 = capRegClass[_CA5Idx],
    CA6 = capRegClass[_CA6Idx],
    CA7 = capRegClass[_CA7Idx],
    CS2 = capRegClass[_CS2Idx],
    CS3 = capRegClass[_CS3Idx],
    CS4 = capRegClass[_CS4Idx],
    CS5 = capRegClass[_CS5Idx],
    CS6 = capRegClass[_CS6Idx],
    CS7 = capRegClass[_CS7Idx],
    CS8 = capRegClass[_CS8Idx],
    CS9 = capRegClass[_CS9Idx],
    CS10 = capRegClass[_CS10Idx],
    CS11 = capRegClass[_CS11Idx],
    CT3 = capRegClass[_CT3Idx],
    CT4 = capRegClass[_CT4Idx],
    CT5 = capRegClass[_CT5Idx],
    CT6 = capRegClass[_CT6Idx],
    CUreg0 = capRegClass[_CUreg0Idx];

const std::vector<std::string> RegNames = {
    "czero", "cra", "csp", "cgp",
    "ctp", "ct0", "ct1", "ct2",
    "cs0", "cs1", "ca0", "ca1",
    "ca2", "ca3", "ca4", "ca5",
    "ca6", "ca7", "cs2", "cs3",
    "cs4", "cs5", "cs6", "cs7",
    "cs8", "cs9", "cs10", "cs11",
    "ct3", "ct4", "ct5", "ct6"
};

} // namespace cap_reg

// Semantically meaningful register indices
inline constexpr auto
    &CReturnAddrReg = cap_reg::Ra,
    &CStackPointerReg = cap_reg::Sp,
    &CThreadPointerReg = cap_reg::Tp,
    &CReturnValueReg = cap_reg::A0,
    &CAMOTempReg = cap_reg::Ureg0,
    &CSyscallNumReg = cap_reg::A7;

inline constexpr RegId CArgumentRegs[] = {
    cap_reg::CA0, cap_reg::CA1, cap_reg::CA2, cap_reg::CA3,
    cap_reg::CA4, cap_reg::CA5, cap_reg::CA6, cap_reg::CA7
};

} // namespace RiscvISA
} // namespace gem5

#endif // __ARCH_RISCV_REGS_CAP_HH__
