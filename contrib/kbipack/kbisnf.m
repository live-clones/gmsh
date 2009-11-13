function [U, S, V] = kbisnf(A)

% [U, S, V] = kbisnf(A)
%
% Computes the integer Smith normal form S such that 
% 
%   A = U*S*V
% 
% Uses external Kannan-Bachem implementation

%    Copyright (C) 4.11.2003 Saku Suuriniemi TUT/CEM
%
%    This program is free software; you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation; either version 2 of the License, or
%    any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program; if not, write to the Free Software
%    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

%   Saku Suuriniemi, TUT/Electromagetics
%   P.O.Box 692, FIN-33101 Tampere, Finland
%   saku.suuriniemi@tut.fi

  [i,j,v] = find(A);

  fid = fopen('snf_temp.crd', 'w');
  fprintf(fid, '%g %g %g\n', size(A,1), size(A,2), length(i));
  if ~isempty(v)
    fprintf(fid, '%g %g %g\n', [i'; j'; v']);
  end
  fclose(fid);

  system ('./compute_normal_form -S snf_temp.crd');

  load snf_temp.left;
  U = zeros(snf_temp(1,1), snf_temp(1,2));
  for i = 2:size(snf_temp,1)
     U(snf_temp(i,1), snf_temp(i,2)) = snf_temp(i,3);
  end

  load snf_temp.can;
  S = zeros(snf_temp(1,1), snf_temp(1,2));
  for i = 2:size(snf_temp,1)
    S(snf_temp(i,1), snf_temp(i,2)) = snf_temp(i,3);
  end

  load snf_temp.right;
  V = zeros(snf_temp(1,1), snf_temp(1,2));
  for i = 2:size(snf_temp,1)
    V(snf_temp(i,1), snf_temp(i,2)) = snf_temp(i,3);
  end
