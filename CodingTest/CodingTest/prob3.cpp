--write your code in PostgreSQL 9.4
ALTER TABLE teams
ADD num_points integer;

UPDATE teams SET num_points = 0;

UPDATE teams SET num_points = num_points + 3
FROM matches M
WHERE teams.team_id = M.host_team AND M.host_goals > M.guest_goals;

UPDATE teams SET num_points = num_points + 1
FROM matches M
WHERE teams.team_id = M.host_team AND M.host_goals = M.guest_goals;

UPDATE teams SET num_points = num_points + 3
FROM matches M
WHERE teams.team_id = M.guest_team AND M.host_goals < M.guest_goals;

UPDATE teams SET num_points = num_points + 1
FROM matches M
WHERE teams.team_id = M.guest_team AND M.host_goals = M.guest_goals;

SELECT * FROM teams
ORDER BY num_points DESC, team_id;
