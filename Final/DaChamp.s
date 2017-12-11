.name "lemme smash"
.comment "u want sum fuk"

start:
	add r1, r2, r3
	st r1, 0
	live %0
	zjmp %:start
