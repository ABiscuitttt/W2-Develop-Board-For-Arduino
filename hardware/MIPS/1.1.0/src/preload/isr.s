   #address 0x3c
###################################################
   #address 0x3c
   .global interrupt_service_routine
   .ent interrupt_service_routine
interrupt_service_routine:
   .set noreorder
   .set noat

   #Registers $26 and $27 are reserved for the OS
   #Save all temporary registers
   #Slots 0($29) through 12($29) reserved for saving a0-a3
   addi  $29, $29, -140  #adjust sp
   sw    $1,  16($29)    #at
   sw    $2,  20($29)    #v0
   sw    $3,  24($29)    #v1
   sw    $4,  28($29)    #a0
   sw    $5,  32($29)    #a1
   sw    $6,  36($29)    #a2
   sw    $7,  40($29)    #a3
   sw    $8,  44($29)    #t0
   sw    $9,  48($29)    #t1
   sw    $10, 52($29)    #t2
   sw    $11, 56($29)    #t3
   sw    $12, 60($29)    #t4
   sw    $13, 64($29)    #t5
   sw    $14, 68($29)    #t6
   sw    $15, 72($29)    #t7
   sw    $24, 76($29)    #t8
   sw    $25, 80($29)    #t9
   sw    $31, 84($29)    #lr
   mfc0  $26, $14        #C0_EPC=14 (Exception PC)
   #sub   $26, $26, 0x4 
   sw    $26, 88($29)    #pc
   lui    $s0, 0x0100
   ori   $s0, $s0, 0x1ff8
   sw    $26, ($s0) #save pc to PC_LOC for debug continue option use
   mfhi  $27
   sw    $27, 92($29)    #hi
   mflo  $27
   sw    $27, 96($29)    #lo
   sw    $30, 100($29)
   sw    $16, 104($29)
   sw    $17, 108($29)
   sw    $18, 112($29)
   sw    $19, 116($29)
   sw    $20, 120($29)
   sw    $21, 124($29)
   sw    $22, 128($29)
   sw    $23, 132($29)
   lui    $8, 0x0100
   ori    $8, $8, 0x1ff4   #get the current interrupt depth
   lw    $9, ($8)
   addi  $9, $9, 1       #increment the interrupt depth
   sw    $9, ($8)       #update the interrupt count
   sll   $9, $9, 2       #calculate the difference between INT_COUNT and current SP storage location
   sub   $8, $8, $9      # this is the location to store SP
   sw    $29, ($8)      #save SP to the location near INT_COUNT
   jal user_interrupt
   nop
#   addi  $5,  $29, 0
   lui    $8, 0x0100
   ori   $8, $8, 0x1ff4   #get the current interrupt depth
   lw    $9, ($8)
   sub   $9, $9, 1       #decrement the interrupt depth
   sw    $9, ($8)       #update the interrupt count

   #Restore all temporary registers
   lw    $1,  16($29)    #at
   lw    $2,  20($29)    #v0
   lw    $3,  24($29)    #v1
   lw    $4,  28($29)    #a0
   lw    $5,  32($29)    #a1
   lw    $6,  36($29)    #a2
   lw    $7,  40($29)    #a3
   lw    $8,  44($29)    #t0
   lw    $9,  48($29)    #t1
   lw    $10, 52($29)    #t2
   lw    $11, 56($29)    #t3
   lw    $12, 60($29)    #t4
   lw    $13, 64($29)    #t5
   lw    $14, 68($29)    #t6
   lw    $15, 72($29)    #t7
   lw    $24, 76($29)    #t8
   lw    $25, 80($29)    #t9
   lw    $31, 84($29)    #lr
   lw    $26, 88($29)    #pc
   lw    $27, 92($29)    #hi
   mthi  $27
   lw    $27, 96($29)    #lo
   mtlo  $27
   lw    $30, 100($29)
   lw    $16, 104($29)
   lw    $17, 108($29)
   lw    $18, 112($29)
   lw    $19, 116($29)
   lw    $20, 120($29)
   lw    $21, 124($29)
   lw    $22, 128($29)
   lw    $23, 132($29)
   addi  $29, $29, 140   #adjust sp
   lui    $gp, 0x0100		#gp for the user program
   ori   $gp, $gp, 0x80F0             #only valid when  user program SRAM start at 01000100

   nop
   jr    $26
   rfe                    # this is important, restore STATUS
   nop

   .set reorder
   .set at

   .end interrupt_service_routine

   #normally clear the interrupt source here








































































