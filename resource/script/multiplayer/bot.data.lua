MaxSquadSize = 16
SpecialPoints = 0

OrderRotationPeriod = 0.5 * 60 * 1000 --1500 ---2.5 * 60 * 1000 -- 2:30 min (ms)

SpawnCooldownTime = {
	Min = 2 * 1000, -- 2 sec (ms)
	Max = 7 * 1000 -- 7 sec (ms)
}
UnitSpawnWaitTime = 0.5 * 60 * 1000 -- 2:30 min (ms)

FlagPriority = { Captured = 1, Enemy = 2, Neutral = 3 }
FlagCaptureArea = {
	Infantry = 9,	-- meters
	Captor = 11,
	Vehicle = 40,
	--Helicopter = 75,
	Artillery = 75
}
-- ai purchases will be limited between min and max
-- early and late costs are linearly interpolated from growthStarts time and growthEnds time
-- time is in game ticks,  1500 -- 30s  6000 2m -- 15000 5m -- 30000 10m -- 45000 -- 15m 90000 -- 30m 135000 -- 45m 180000 -- 60m 225000 -- 75m 270000 -- 90m 315000 -- 105m
-- hero unit costs are in sp


UnitClass = {
	Infantry = "infantry",
	ATInfantry = "at-infantry",
	Vehicle = "vehicle",
	Tank = "tank",
	AATank = "aa-tank",
	ATTank = "at-tank",
	HeavyTank = "heavy-tank",
	ArtilleryTank = "artillery-tank",
}

Purchases = {}
require([[/script/multiplayer/bot.data.purchase.standard]])
Purchases["ammunition"] = Purchases["standard"]
Purchases["battle_zones"] = Purchases["standard"]
Purchases["combined_arms"] = Purchases["standard"]
Purchases["koth"] = Purchases["standard"]
Purchases["evacuation"] = Purchases["standard"]