//
// Created by alexander on 2019-09-24.
//

#include "48_delta.h"

synth_register_t const synth_registers_delta_48[DELTA_48_CONFIG_NUM_REGS] =
        {
                { 0x0B24, 0xC0 },
                { 0x0B25, 0x00 },
                { 0x0502, 0x01 },
                { 0x0505, 0x03 },
                { 0x0957, 0x17 },
                { 0x0B4E, 0x1A },
                { 0x0115, 0x28 },
                { 0x011A, 0x29 },
                { 0x0238, 0x00 },
                { 0x0239, 0x11 },
                { 0x023A, 0x01 },
                { 0x023D, 0x00 },
                { 0x023E, 0xFA },
                { 0x0250, 0x0D },
                { 0x0253, 0x01 },
                { 0x025C, 0x06 },
                { 0x025F, 0x01 },
                { 0x0306, 0x13 },
                { 0x0310, 0x00 },
                { 0x0311, 0x20 },
                { 0x0312, 0x08 },
                { 0x0316, 0xE0 },
                { 0x031A, 0x00 },
                { 0x031B, 0x80 },
                { 0x031C, 0x88 },
                { 0x0320, 0x00 },
                { 0x0321, 0xFA },
                { 0x001C, 0x01 },
                { 0x0B24, 0xC3 },
                { 0x0B25, 0x02 },
        };