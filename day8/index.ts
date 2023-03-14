#!/usr/bin/env node
import fs = require('fs');

const text: string = fs.readFileSync('./input.txt').toString();
const lines: string[] = text.split('\n');

const input: number[][] = [];

for (let y = 0; y < lines.length; y++) {
    const newRow: number[] = [];
    for (let x = 0; x < lines[y].length; x++) {
        if (!Number.isNaN(Number.parseInt(lines[y][x]))) {
            newRow.push(Number.parseInt(lines[y][x]));
        }
    }
    input.push(newRow);
}


