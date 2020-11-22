(define "accuracy_by_motion" ;  spreading depending on the speed of "body", "gun" volumes
	{AccuracyByMotion
        {MaxLinearSpeed %max_linear}               ;km/h
        {ByLinearSpeed %accuracy_by_linear}
        {MaxAngularSpeed %max_angular}             ;deg/s
        {ByAngularSpeed %accuracy_by_angular}
        {DisorderTime %disorder_time}              ;s
        {OrderTime %order_time}                    ;s
    }
)

(define "abm_low"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.2)
        max_angular(6) accuracy_by_angular(0.6)
        disorder_time(4.5) order_time(2)
    )
)
(define "abm_medium"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.2)
        max_angular(6) accuracy_by_angular(0.6)
        disorder_time(4.5) order_time(3)
    )
)
(define "abm_high"
    ("accuracy_by_motion"
        max_linear(9) accuracy_by_linear(0.2)
        max_angular(6) accuracy_by_angular(0.6)
        disorder_time(4.5) order_time(4)
    )
)

(define "abm_zenite"
    ("accuracy_by_motion"
        max_linear(16) accuracy_by_linear(0.2)
        max_angular(40) accuracy_by_angular(0.8)
        disorder_time(4.5) order_time(2)
    )
)
(define "abm_howitzer"
    ("accuracy_by_motion"
        max_linear(5) accuracy_by_linear(0.95)
        max_angular(1) accuracy_by_angular(0.95)
        disorder_time(1.5) order_time(25)
     )
)
(define "abm_mgun"
	("accuracy_by_motion"
        max_linear(16) accuracy_by_linear(0.2)
		max_angular(40) accuracy_by_angular(0.8)
		disorder_time(4.5) order_time(1)
     )
)
(define "abm_mgun_heavy"
	("accuracy_by_motion"
        max_linear(16) accuracy_by_linear(0.2)
		max_angular(40) accuracy_by_angular(0.8)
		disorder_time(4.5) order_time(1.5)
     )
)