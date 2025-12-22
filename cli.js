#!/usr/bin/env node
const { spawn } = require('child_process');
const path = require('path');
const os = require('os');
const fs = require('fs');
const packageJson = require('./package.json');

const args = process.argv.slice(2); // Mengambil argumen setelah 'brot'

// 1. Handling: --version atau -v
if (args.includes('--version') || args.includes('-v')) {
    console.log(`BrainrotLang Version: ${packageJson.version}`);
    process.exit(0);
}

// 2. Handling: --help atau -h
if (args.includes('--help') || args.includes('-h')) {
    console.log(`Usage: brot <filename.brainrot> [options]`);
    console.log(`\nOptions:`);
    console.log(`  -h, --help     Menampilkan bantuan ini`);
    console.log(`  -v, --version  Menampilkan versi BrainrotLang`);
    console.log(`\nContoh:`);
    console.log(`  brot example.brainrot`);
    process.exit(0);
}

// 3. Handling: Jika tidak ada argumen sama sekali (Fatal Error)
if (args.length === 0) {
    console.error(`brot: fatal error: no input files`);
    console.error(`compilation terminated.`);
    process.exit(1);
}

// Tentukan path binary berdasarkan OS
const isWin = os.platform() === 'win32';
const binaryName = isWin ? 'brot.exe' : 'brot';
const binaryPath = path.join(__dirname, 'bin', binaryName);

// 4. Validasi keberadaan file input (.brainrot)
const inputFile = args[0];
if (!fs.existsSync(inputFile)) {
    console.error(`brot: error: ${inputFile}: No such file or directory`);
    process.exit(1);
}

if (!fs.existsSync(binaryPath)) {
    console.error("Error: Interpreter BrainrotLang tidak ditemukan. Jalankan 'npm install' ulang.");
    process.exit(1);
}

// 5. Jalankan binary C jika semua validasi lolos
const child = spawn(binaryPath, args, { stdio: 'inherit' });

child.on('exit', (code) => {
    process.exit(code || 0);
});