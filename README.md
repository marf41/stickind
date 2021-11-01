# Intro

When using sticky keys:
```
xkbset sticky -twokey # mod keys stick
xkbset exp 1 =accessx =sticky =twokey # disable expiry
```

, I could not find a way to check currently active modifiers.

Thus, this little code was born.

# Usage

Default output, with no modifiers active:
```
- -
```

Left group is latched (will mod next key), right group is locked (active until pressed again).

Call binary with `-h` to see help text, and symbols meaning:
```
	Returns status of latched and locked mods.
		'-' - no mods active.
		'S' - 'Shift' active.
		'C' - 'Control' active.
		'A' - 'Alt' active.
		'G' - 'AltGr' active.
		'W' - 'Windows' active.
```
