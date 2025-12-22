#!/usr/bin/env node
const { spawn } = require('child_process');
const path = require('path');
const os = require('os');
const fs = require('fs');

// Tentukan nama binary berdasarkan OS
const isWin = os.platform() === 'win32';
const binaryName = isWin ? 'brot.exe' : 'brot';
const binaryPath = path.join(__dirname, 'bin', binaryName);

if (!fs.existsSync(binaryPath)) {
    console.error("Error: Interpreter BrainrotLang tidak ditemukan. Coba instal ulang.");
    process.exit(1);
}

// Jalankan binary dan teruskan semua argumen 
const child = spawn(binaryPath, process.argv.slice(2), { stdio: 'inherit' });

child.on('exit', (code) => {
    process.exit(code || 0);
});
