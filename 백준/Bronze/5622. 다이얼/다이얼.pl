sub timeForChar {
    $ch = shift;
    return 3 if ( $ch lt 'D' );
    return 4 if ( $ch lt 'G' );
    return 5 if ( $ch lt 'J' );
    return 6 if ( $ch lt 'M' );
    return 7 if ( $ch lt 'P' );
    return 8 if ( $ch lt 'T' );
    return 9 if ( $ch lt 'W' );
    return 10;
}

$n = <>;
$time = 0;
$time += timeForChar(substr($n, $_, 1)) for (0..(length $n)-2);
printf("%d\n", $time);