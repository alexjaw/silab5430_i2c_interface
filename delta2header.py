#!/usr/bin/env python
""" Helper that takes csv files that CBpro produces and
    outputs c header equivalents.

    Example:
        ./delta2header.py 002_delta.txt 48 synth_config.h
"""
import sys


def is_reg(row):
    if (len(row) == 2) and ('#' not in row[0]) and ('Address' not in row[0]):
        return True
    return False


src = sys.argv[1]
delta_name = sys.argv[2]
full_config_header_file_name = sys.argv[3]
dst = delta_name + '_delta.h'
print('src: {}'.format(src))
print('dst: {}'.format(dst))
print('delta_name: {}'.format(delta_name))
print('full_config_header_file_name: {}'.format(full_config_header_file_name))
assert '.h' in full_config_header_file_name

_lines = []
lines = []
import csv
with open(src, newline='') as f:
    reader = csv.reader(f)
    for row in reader:
        if is_reg(row):
            #print(row)
            _lines.append(''.join(['\t', '{ ', row[0], ', ', row[1], ' },']))

lines.append(''.join(['#ifndef SYNTH_', delta_name.upper(), '_DELTA_HEADER']))
lines.append(''.join(['#define SYNTH_', delta_name.upper(), '_DELTA_HEADER']))
lines.append('#include "' + full_config_header_file_name + '"')
num_regs_define_name = 'DELTA_' + delta_name + '_CONFIG_NUM_REGS'
lines.append(' '.join(['#define', num_regs_define_name, str(len(_lines))]))
lines.append(''.join(['synth_register_t const synth_registers_delta_', delta_name, '[', num_regs_define_name, '] =\n{']))
for _line in _lines:
    lines.append(_line)
lines.append('};')
lines.append('#endif')

with open(dst, 'w') as f:
    f.writelines('{}\n'.format(line) for line in lines )
