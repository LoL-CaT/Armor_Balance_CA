; == STANDARD ==
(define "test_all"
	{common
		{unitset
			{value "all|combined_arms"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{balancingFactorBonus {cp 1.0}}
		{chargeFactors
			{value "*=0"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource
					{start		%start}
					{finish		%finish}
					{growTime	1500}		; in seconds
					{growTable	"0.65 0.65 0.65 0.70 0.70 0.70 0.75 0.75 0.75 0.80 0.80 0.80 0.80 0.80 0.80 0.85 0.85 0.85 0.90 0.90 0.90 0.90 0.90 0.90 1.00"}
					{payback
						{cp			"0		25		50		60		70		80		90"}
						{restore	"1.50	1.25	0.75	0.50	0.40	0.30	0.20"}
					}
				}
				{buttons "s1 s2 v1 v2 v3 v4 v5"}
			}
			{hero
				{resource
					{start		1000}
				}
				{buttons "hero"}
				{tag "special"}
			}
		}
	}
	{bots
		{easy
			{balancingFactorBonus {cp 0.10}}
			{chargeFactors
				{value "*=0"}
			}
		}
		{normal
			{balancingFactorBonus {cp 0.15}}
			{chargeFactors
				{value "*=0"}
			}
		}
		{hard
			{balancingFactorBonus {cp 0.20}}
			{chargeFactors
				{value "*=0"}
			}
		}
		{heroic
			{balancingFactorBonus {cp 0.25}}
			{chargeFactors
				{value "*=0"}
			}
		}
	}
)

;------------------------------------------------------------------------------------------------------------
{presets
	{"s:test_all"
		{gameMode "test"}
		{unitMode "all"}
		{specMode "all_normal"}
		("test_all"			start(50000) finish(50000) cp(1000))
	}
;------------------------------------------------------------------------------------------------------------
}