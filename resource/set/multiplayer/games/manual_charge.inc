(define "manual_charge_short"
	{manualCharge
		{enabled}
		{initCharge 0} ; sec
		{minCharge 10} ; sec
		{maxCharge 60} ; sec
		{chargeGain 0.2} ; sec gain per 1 second
		{playerScoreFactor 0.25} ; sec per 1 score point
		{enemyScoreFactor 0.125} ; sec per 1 score point
	}
)
(define "manual_charge_long"
	{manualCharge
		{enabled}
		{initCharge 0} ; sec
		{minCharge 20} ; sec
		{maxCharge 180} ; sec
		{chargeGain 1} ; sec gain per 1 second
		{playerScoreFactor 0.5} ; sec per 1 score point
		{enemyScoreFactor 0.25} ; sec per 1 score point
	}
)