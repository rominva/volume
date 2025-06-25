# Volume Modifier for WAV Files

This project is a solution to the CS50 Volume problem, part of the [CS50x](https://cs50.harvard.edu/x) course.

The program reads a `.wav` audio file and outputs a new `.wav` file with its volume scaled by a specified factor. It preserves the header of the original file and modifies only the audio samples.

## 📁 Files

- `volume.c`: Main source code file.
- `input.wav`: Example input file (not included, provide your own).
- `output.wav`: Output file generated after processing.
- `README.md`: This file.

## ⚙️ How It Works

- A WAV file contains a 44-byte header followed by 16-bit signed samples.
- The program copies the 44-byte header from the input file to the output file.
- Then it reads each 2-byte sample, multiplies it by a user-specified factor, and writes the result to the output file.

## 🚀 Usage

Compile the program with:

```bash
make volume
```

Run the program with:

```bash
./volume input.wav output.wav factor
```

- `input.wav`: Path to the original audio file.
- `output.wav`: Desired name of the output file.
- `factor`: A float value by which to scale the volume (e.g., 0.5 to halve, 2.0 to double).

### Example:

```bash
./volume input.wav louder.wav 2.0
```

## 🔒 Notes

- The program assumes all WAV files use 16-bit signed integer samples.
- Be sure to test with valid `.wav` files only.
- For use in environments outside CS50, it's recommended to use `"rb"` and `"wb"` instead of `"r"` and `"w"` for file modes, to ensure binary safety on all platforms.

## ✅ CS50 Specification

This program was written to pass `check50` and `style50` checks for the CS50 course.

---

Made with ❤️ for learning.